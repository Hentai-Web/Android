package com.dergoogler.hentai.tools;

public class Lib {
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("node");
    }

    public static String getReleaseURl = "https://hw.dergoogler.com";
    public static String getDebugURl = "http://192.168.178.81:5500/";
    public static String getInterfaceName = "Android";
    public static String getUserAgent = "HENTAI_WEB_AGENT";
    public static String getStorageKey = "localstorage";
    public static String getFolderPath = "/hentai-web/";
    public static String getFingerprintPrefKey = "useFingerPrintToLogin";
    public static String getLanguagePrefKey = "language";
    public static String en = "en";
    public static String getTrue = "true";
    public static String getBiometricPromptTitle = "Biometric login for Hentai Web";
    public static String getBiometricPromptSubTitle = "Log in using your biometric credential";
    public static String getBiometricPromptButtonTitle = "Use password";
    public static String SCHEME_HTTP = "http://";
    public static String SCHEME_HTTPS = "https://";
    public static String SCHEME_FILE = "file://";
    public static String SCHEME_ASSET = "file://android_asset";
    public static String SCHEME_RES = "file://android_res";


    public native static Integer startNodeWithArguments(String[] arguments);
}
