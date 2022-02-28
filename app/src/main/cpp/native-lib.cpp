#include <jni.h>
#include <string>
#include <cstdlib>
#include "node.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_yourorg_sample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" jobject JNICALL
Java_com_dergoogler_hentai_tools_Lib_startNodeWithArguments(
        JNIEnv *env,
        jclass clazz,
        jobjectArray arguments) {

    //argc
    jsize argument_count = env->GetArrayLength(arguments);

    //Compute byte size need for all arguments in contiguous memory.
    int c_arguments_size = 0;
    for (int i = 0; i < argument_count; i++) {
        c_arguments_size += strlen(
                env->GetStringUTFChars((jstring) env->GetObjectArrayElement(arguments, i), 0));
        c_arguments_size++; // for '\0'
    }

    //Stores arguments in contiguous memory.
    char *args_buffer = (char *) calloc(c_arguments_size, sizeof(char));

    //argv to pass into node.
    char *argv[argument_count];

    //To iterate through the expected start position of each argument in args_buffer.
    char *current_args_position = args_buffer;

    //Populate the args_buffer and argv.
    for (int i = 0; i < argument_count; i++) {
        const char *current_argument = env->GetStringUTFChars(
                (jstring) env->GetObjectArrayElement(arguments, i), 0);

        //Copy current argument to its expected position in args_buffer
        strncpy(current_args_position, current_argument, strlen(current_argument));

        //Save current argument start position in argv
        argv[i] = current_args_position;

        //Increment to the next argument's expected position.
        current_args_position += strlen(current_args_position) + 1;
    }

    //Start node, with argc and argv.
    return reinterpret_cast<jobject>(jint(node::Start(argument_count, argv)));

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dergoogler_hentai_tools_Lib_getReleaseURl(JNIEnv *env, jclass clazz) {
    std::string data = "https://hw.dergoogler.com";
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
Java_com_dergoogler_hentai_tools_Lib_getTrue(JNIEnv *env, jclass clazz) {
    std::string data = "true";
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