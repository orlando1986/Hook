/*
 * libmynet.c
 *
 *  Created on: 2013-1-17
 *      Author: d
 */

#include <jni.h>
#include <stdio.h>
#include "utils.h"
#include "Proxy.h"

extern "C" {

static void Hook_hookMethodNative(JNIEnv* env, jclass clazz,
		jobject reflectedMethodIndirect) {
	hookMethod(env, clazz, reflectedMethodIndirect);
}

const JNINativeMethod gMethods[] = { { "hookMethodNative",
		"(Ljava/lang/reflect/Method;)V", (void *) Hook_hookMethodNative } };

static int register_android_jni(JNIEnv *env, jclass clazz) {
	return env->RegisterNatives(clazz, gMethods, sizeof(gMethods));
}

static jclass sTargetClass = 0;
#define SIZE 0x100
static const char* PATHS[SIZE];
static jclass CLASS[SIZE];
static int sSize = 0;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	jint result = -1;

	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return -1;
	}
	assert(env != NULL);

	jclass proxyClass = env->FindClass("com/catfish/undercover/HookManager");

	register_android_jni(env, proxyClass);
	initMembers(env, proxyClass);

	result = JNI_VERSION_1_4;

	return result;
}
}
