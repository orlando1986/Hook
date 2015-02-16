LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := hook/libhook.cpp hook/Proxy.cpp 
LOCAL_MODULE := libhook
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
	libdvm \
LOCAL_CFLAGS := -DANDROID_NDK

LOCAL_LDLIBS += -L$(LOCAL_PATH)/hook -ldvm
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog
#LOCAL_C_INCLUDES := 
include $(BUILD_SHARED_LIBRARY)
