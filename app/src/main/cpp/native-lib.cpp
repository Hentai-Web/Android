#include <jni.h>
#include <string>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <android/log.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getReleaseURl(JNIEnv *env, jclass clazz) {
    std::string data = "https://dergoogler.com/hentai-web/";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getDebugURl(JNIEnv *env, jclass clazz) {
    std::string data = "http://192.168.178.81:5500/";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getInterfaceName(JNIEnv *env, jclass clazz) {
    std::string data = "Android";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getUserAgent(JNIEnv *env, jclass clazz) {
    std::string data = "HENTAI_WEB_AGENT";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getStorageKey(JNIEnv *env, jclass clazz) {
    std::string data = "localstorage";
    return env->NewStringUTF(data.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getFolderPath(JNIEnv *env, jclass clazz) {
    std::string data = "/hentai-web/";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getFingerprintPrefKey(JNIEnv *env, jclass clazz) {
    std::string data = "useFingerPrintToLogin";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getLanguagePrefKey(JNIEnv *env, jclass clazz) {
    std::string data = "language";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_en(JNIEnv *env, jclass clazz) {
    std::string data = "en";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getBiometricPromptTitle(JNIEnv *env, jclass clazz) {
    std::string data = "Biometric login for Hentai Web";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getBiometricPromptSubTitle(JNIEnv *env, jclass clazz) {
    std::string data = "Log in using your biometric credential";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getBiometricPromptButtonTitle(JNIEnv *env, jclass clazz) {
    std::string data = "Use password";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getTrue(JNIEnv *env, jclass clazz) {
    std::string data = "true";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_SCHEME_1HTTP(JNIEnv *env, jclass clazz) {
    std::string data = "http://";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_SCHEME_1HTTPS(JNIEnv *env, jclass clazz) {
    std::string data = "https://";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_SCHEME_1FILE(JNIEnv *env, jclass clazz) {
    std::string data = "file://";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_SCHEME_1ASSET(JNIEnv *env, jclass clazz) {
    std::string data = "file://android_asset";
    return env->NewStringUTF(data.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_SCHEME_1RES(JNIEnv *env, jclass clazz) {
    std::string data = "file://android_res";
    return env->NewStringUTF(data.c_str());
}