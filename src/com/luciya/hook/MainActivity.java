package com.luciya.hook;

import java.lang.reflect.Method;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;

import com.catfish.undercover.HookManager;
import com.catfish.undercover.HookedCallback;
import com.catfish.undercover.HookedMethod;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        testHook();
        victimMethod();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    private void testHook() {
        try {
            Method m = getClass().getDeclaredMethod("victimMethod", (Class[]) null);
            HookManager.setMethodHooked(m, new HookedCallback() {
                @Override
                public Object invoke(HookedMethod method, Object receiver, Object[] args) {
                    Log.i("catfish", "hooked sucess!");
                    return null;
                }
            });
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
    }

    private void victimMethod() {
        Log.d("catfish", "hooked failed");
    }
}
