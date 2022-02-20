package com.dergoogler.hentai.tools;

public class Lib {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String getReleaseURl();

    public static native String getDebugURl();

    public static native String getInterfaceName();

    public static native String getUserAgent();

    public static native String getStorageKey();

    public static native String getFolderPath();

    public static native String getFingerprintPrefKey();

    public static native String getLanguagePrefKey();

    public static native String en();

    public static native String getTrue();

    public static native String getBiometricPromptTitle();

    public static native String getBiometricPromptSubTitle();

    public static native String getBiometricPromptButtonTitle();

    public static native String SCHEME_HTTP();

    public static native String SCHEME_HTTPS();

    public static native String SCHEME_FILE();

    public static native String SCHEME_ASSET();

    public static native String SCHEME_RES();

}
