#include "Dalvik.h"
#include <jni.h>
#include "utils.h"

void hookMethod(JNIEnv* env, jclass clazz, jobject reflectedMethodIndirect);
void initMembers(JNIEnv* env, jclass xposedClass);
