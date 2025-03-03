/*===============================================================================
Copyright (c) 2015-2018 PTC Inc. All Rights Reserved.
 
Copyright (c) 2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.
 
Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
===============================================================================*/

using UnityEngine;
using UnityEngine.Events;

public class TapHandler : MonoBehaviour
{
    public UnityEvent SingleTapConfirmedEvent = new UnityEvent();
    public UnityEvent DoubleTapEvent = new UnityEvent();
    const float DOUBLE_TAP_MAX_DELAY_IN_SECONDS = 0.5f;
    
    float mTimeSinceLastTap;
    int mTapCount;
    
    void Start()
    {
        mTapCount = 0;
        mTimeSinceLastTap = 0;
    }

    void Update()
    {
        HandleTap();
    }
    
    void HandleTap()
    {
        if (mTapCount == 1)
        {
            mTimeSinceLastTap += Time.deltaTime;
            if (mTimeSinceLastTap > DOUBLE_TAP_MAX_DELAY_IN_SECONDS)
            {
                mTapCount = 0;
                mTimeSinceLastTap = 0;
                
                // too late for double tap, 
                // we confirm it was a single tap
                OnSingleTapConfirmed();

                // reset touch count and timer
            }
        }
        else if (mTapCount == 2)
        {
            // we got a double tap
            OnDoubleTap();

            // reset touch count and timer
            mTimeSinceLastTap = 0;
            mTapCount = 0;
        }

        if (Input.GetMouseButtonUp(0))
        {
            mTapCount++;
            if (mTapCount == 1)
                OnSingleTap();
        }
    }
    
    /// <summary>
    /// This method can be overridden by custom (derived) TapHandler implementations,
    /// to perform special actions upon single tap.
    /// </summary>
    protected virtual void OnSingleTap() { }

    protected virtual void OnSingleTapConfirmed()
    {
        SingleTapConfirmedEvent?.Invoke();
    }

    protected virtual void OnDoubleTap()
    {
        DoubleTapEvent?.Invoke();
    }
}
