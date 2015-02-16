package com.catfish.undercover;

public interface HookedCallback {
    public Object invoke(HookedMethod method, Object receiver, Object[] args);
}