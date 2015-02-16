/*
 * ptrace.h
 *
 *  Created on: Jun 4, 2011
 *      Author: d
 */

#ifndef PTRACE_H_
#define PTRACE_H_



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>
#ifdef ANDROID
#include <linux/user.h>
#else
#include <sys/user.h>
#endif

#include <stdarg.h>
#ifdef ANDROID
typedef struct pt_regs regs_t;
#else
typedef struct user_regs_struct regs_t;
#endif

#define HOOK_LIB   "libhook.so"
#define TAG    "catfish"

#define DEBUG 0
#define LOGV(fmt, args...) if (DEBUG) __android_log_print(ANDROID_LOG_VERBOSE, TAG, fmt, ##args)
#define LOGI(fmt, args...) if (DEBUG) __android_log_print(ANDROID_LOG_INFO, TAG, fmt, ##args)
#define LOGD(fmt, args...) if (DEBUG) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGE(fmt, args...) if (DEBUG) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)
#define LOGW(fmt, args...) if (DEBUG) __android_log_print(ANDROID_LOG_WARN, TAG, fmt, ##args)

#endif /* PTRACE_H_ */
