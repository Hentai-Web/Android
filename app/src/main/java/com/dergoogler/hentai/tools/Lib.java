package com.dergoogler.hentai.tools;

public class Lib {
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("node");
    }

    public static String getReleaseURl = getReleaseURl();
    public static String getDebugURl = getDebugURl();
    public static String getInterfaceName = getInterfaceName();
    public static String getUserAgent = getUserAgent();
    public static String getStorageKey = getStorageKey();
    public static String getFolderPath = getFolderPath();
    public static String getFingerprintPrefKey = getFingerprintPrefKey();
    public static String getLanguagePrefKey = getLanguagePrefKey();
    public static String en = en();
    public static String getTrue = getTrue();
    public static String getBiometricPromptTitle = getBiometricPromptTitle();
    public static String getBiometricPromptSubTitle = getBiometricPromptSubTitle();
    public static String getBiometricPromptButtonTitle = getBiometricPromptButtonTitle();
    public static String SCHEME_HTTP = SCHEME_HTTP();
    public static String SCHEME_HTTPS = SCHEME_HTTPS();
    public static String SCHEME_FILE = SCHEME_FILE();
    public static String SCHEME_ASSET = SCHEME_ASSET();
    public static String SCHEME_RES = SCHEME_RES();

    private native static String getReleaseURl();

    private native static String getDebugURl();

    private native static String getInterfaceName();

    private native static String getUserAgent();

    private native static String getStorageKey();

    private native static String getFolderPath();

    private native static String getFingerprintPrefKey();

    private native static String getLanguagePrefKey();

    private native static String en();

    private native static String getTrue();

    private native static String getBiometricPromptTitle();

    private native static String getBiometricPromptSubTitle();

    private native static String getBiometricPromptButtonTitle();

    private native static String SCHEME_HTTP();

    private native static String SCHEME_HTTPS();

    private native static String SCHEME_FILE();

    private native static String SCHEME_ASSET();

    private native static String SCHEME_RES();

    public native static Object startNodeWithArguments(String[] arguments);
}
