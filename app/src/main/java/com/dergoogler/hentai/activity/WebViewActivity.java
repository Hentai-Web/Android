package com.dergoogler.hentai.activity;

import android.Manifest;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;

import androidx.biometric.BiometricPrompt;

import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.view.KeyEvent;
import android.webkit.WebView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import androidx.core.content.ContextCompat;

//import com.dergoogler.hentai.BuildConfig;
import com.dergoogler.hentai.R;
import com.dergoogler.hentai.tools.Lib;
import com.dergoogler.hentai.zero.activity.BaseActivity;
import com.dergoogler.hentai.zero.dialog.DialogBuilder;
import com.dergoogler.hentai.zero.keyevent.BackKeyShutdown;
import com.dergoogler.hentai.zero.util.FileUtil;
import com.dergoogler.hentai.zero.webview.CSDownloadListener;
import com.dergoogler.hentai.zero.webview.CSWebChromeClient;
import com.dergoogler.hentai.zero.webview.CSWebViewClient;
import com.dergoogler.hentai.bridge.AndroidBridge;
import com.dergoogler.hentai.webview.WebViewHelper;

import java.util.Objects;
import java.util.concurrent.Executor;

public class WebViewActivity extends BaseActivity {
    private static final String TAG = WebViewActivity.class.getSimpleName();
    private SharedPreferences nativaeLocalstorage;
    private WebView webview;

    //We just want one instance of node running in the background.
    public static boolean _startedNodeAlready=false;

    @RequiresApi(api = Build.VERSION_CODES.R)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if( !_startedNodeAlready ) {
            _startedNodeAlready=true;
            new Thread(new Runnable() {
                @Override
                public void run() {
                    Lib.startNodeWithArguments(new String[]{"node", "-e",
                            "var http = require('http'); " +
                                    "var versions_server = http.createServer( (request, response) => { " +
                                    "  response.end('Versions: ' + JSON.stringify(process.versions)); " +
                                    "}); " +
                                    "versions_server.listen(3000);"
                    });
                }
            }).start();
        }

        nativaeLocalstorage = this.getSharedPreferences(Lib.getStorageKey, Activity.MODE_PRIVATE);

        if (!nativaeLocalstorage.contains(Lib.getLanguagePrefKey)) {
            nativaeLocalstorage.edit().putString(Lib.getLanguagePrefKey, Lib.en).apply();
        }

        if (android.os.Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            if (!Environment.isExternalStorageManager()) {
                Intent intent = new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION);
                Uri uri = Uri.fromParts("package", ((Activity) getContext()).getPackageName(), null);
                intent.setData(uri);
                ((Activity) getContext()).startActivity(intent);
            }
        } else {
            if (getContext().checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED) {
                ((Activity) getContext()).requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE, Manifest.permission.MANAGE_EXTERNAL_STORAGE}, 1000);
            }
        }

        login();
    }

    @RequiresApi(api = Build.VERSION_CODES.R)
    private void login() {
        Executor executor = ContextCompat.getMainExecutor(this);
        BiometricPrompt biometricPrompt = new BiometricPrompt(WebViewActivity.this,
                executor, new BiometricPrompt.AuthenticationCallback() {
            @Override
            public void onAuthenticationError(int errorCode,
                                              @NonNull CharSequence errString) {
                super.onAuthenticationError(errorCode, errString);
                Toast.makeText(getApplicationContext(),
                        "Authentication error: " + errString + "(" + errorCode + ")", Toast.LENGTH_SHORT)
                        .show();
            }

            @Override
            public void onAuthenticationSucceeded(
                    @NonNull BiometricPrompt.AuthenticationResult result) {
                super.onAuthenticationSucceeded(result);
                init();
            }

            @Override
            public void onAuthenticationFailed() {
                super.onAuthenticationFailed();
                Toast.makeText(getApplicationContext(), "Authentication failed",
                        Toast.LENGTH_SHORT)
                        .show();
            }
        });

        BiometricPrompt.PromptInfo promptInfo = new BiometricPrompt.PromptInfo.Builder()
                .setTitle(Lib.getBiometricPromptTitle)
                .setSubtitle(Lib.getBiometricPromptSubTitle)
                .setNegativeButtonText(Lib.getBiometricPromptButtonTitle)
                .build();

        if (nativaeLocalstorage.getString(Lib.getFingerprintPrefKey, "").equals(Lib.getTrue)) {
            biometricPrompt.authenticate(promptInfo);
        } else {
            init();
        }

        //if (BuildConfig.DEBUG) {
            WebView.setWebContentsDebuggingEnabled(true);
        //}
    }

    @RequiresApi(api = Build.VERSION_CODES.R)
    @SuppressLint("AddJavascriptInterface")
    private void init() {
        WebView contentView = findViewById(R.id.contentView);

        this.webview = WebViewHelper.addWebView(getContext(), contentView);

        CSWebViewClient webviewClient = new CSWebViewClient(getContext());
        this.webview.setWebViewClient(webviewClient);

        CSWebChromeClient webChromeClient = new CSWebChromeClient(getContext());
        this.webview.setWebChromeClient(webChromeClient);

        this.webview.addJavascriptInterface(new AndroidBridge(webview), Lib.getInterfaceName);

        this.webview.setDownloadListener(new CSDownloadListener(getActivity()));

        Objects.requireNonNull(getSupportActionBar()).hide();

        FileUtil.makeDir(Environment.getExternalStorageDirectory() + Lib.getFolderPath);

        if (FileUtil.readFile(FileUtil.getExternalStorageDir() + Lib.getFolderPath + "debug.txt").equals(Lib.getTrue)) {
            WebViewHelper.loadUrl(this.webview, Lib.getDebugURl);
        } else {
            WebViewHelper.loadUrl(this.webview, Lib.getReleaseURl);
        }
        WebViewHelper.setUserAgentString(this.webview, Lib.getUserAgent);


    }

    @Override
    protected void onDestroy() {
        WebViewHelper.removeWebView(this.webview);
        this.webview = null;
        super.onDestroy();
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (KeyEvent.KEYCODE_BACK == keyCode) {
            if (this.webview.canGoBack()) {
                this.webview.goBack();
                return true;
            }

            if (BackKeyShutdown.isFirstBackKeyPress(keyCode, event)) {
                DialogBuilder.with(getContext())
                        .setMessage("Please the Back button once more shut down.")
                        .toast();
                return true;
            }
        }
        return super.onKeyDown(keyCode, event);
    }
}

