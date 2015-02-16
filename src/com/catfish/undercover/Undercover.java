package com.catfish.undercover;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import android.app.Application;
import android.util.Log;

import com.catfish.undercover.HookedMethod.HookedCallback;

public class Undercover {
    public final static String TAG = "catfish";

    public void onInject(Application application) {
        Log.e(TAG, "hook starts");
        hookSystem();
    }

    private void hookSystem() {
        Class servicemanager;
        Method m = null;
        try {
            servicemanager = Class.forName("android.os.ServiceManager");
            Method getService = servicemanager.getDeclaredMethod("getService", String.class);
            final Object am = getService.invoke(null, "activity");

            Class IApplicationThread = Class.forName("android.app.IApplicationThread");
            m = am.getClass().getDeclaredMethod("attachApplication", IApplicationThread);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (IllegalArgumentException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        HookManager.setMethodHooked(m, new HookedCallback() {

            @Override
            public Object invoke(HookedMethod method, Object receiver, Object[] args) {
                Log.e(TAG, "app starts, you can find the app name from logcat");
                return method.invoke(receiver, args); //must invoke orginal method like this
            }
            
        });
    }
}