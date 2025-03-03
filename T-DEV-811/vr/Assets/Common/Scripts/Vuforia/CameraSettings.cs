/*===============================================================================
Copyright (c) 2015-2018 PTC Inc. All Rights Reserved.

Copyright (c) 2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/
using UnityEngine;
using System.Collections;
using Vuforia;

public class CameraSettings : MonoBehaviour
{
    bool mHasVuforiaStarted = false;
    bool mIsAutofocusEnabled = true;
    bool mIsFlashTorchEnabled = false;
    bool mIsFocusing = false;
    public static bool DoubleTap
    {
        get { return Input.touchSupported && (Input.touches.Length > 0) && (Input.touches[0].tapCount == 2); }
    }
    
    void Start()
    {
        VuforiaApplication.Instance.OnVuforiaStarted += OnVuforiaStarted;
    }

    void Update()
    {
        if (DoubleTap && !mIsFocusing)
        {
            mIsFocusing = true;
            TriggerAutofocusEvent();
        }
    }

    void OnDestroy()
    {
        VuforiaApplication.Instance.OnVuforiaStarted -= OnVuforiaStarted;
    }

    public bool IsFlashTorchEnabled()
    {
        return mIsFlashTorchEnabled;
    }

    public void SwitchFlashTorch(bool ON)
    {
        if (VuforiaBehaviour.Instance.CameraDevice.SetFlash(ON))
        {
            Debug.Log("Successfully turned flash " + ON);
            mIsFlashTorchEnabled = ON;
        }
        else
        {
            Debug.Log("Failed to set the flash torch " + ON);
            mIsFlashTorchEnabled = false;
        }
    }

    public bool IsAutofocusEnabled()
    {
        return mIsAutofocusEnabled;
    }

    public void SwitchAutofocus(bool ON)
    {
        if (ON)
        {
            if (VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_CONTINUOUSAUTO))
            {
                Debug.Log("Successfully enabled continuous autofocus.");
                mIsAutofocusEnabled = true;
            }
            else
            {
                // Fallback to fixed focus mode
                Debug.Log("Failed to enable continuous autofocus, switching to fixed focus mode");
                mIsAutofocusEnabled = false;
                VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_FIXED);
            }
        }
        else
        {
            Debug.Log("Disabling continuous autofocus (enabling fixed focus mode).");
            mIsAutofocusEnabled = false;
            VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_FIXED);

        }
    }

    public void TriggerAutofocusEvent()
    {
        StatusMessage.Display("Manual Focus Triggered", true);
        
        // Trigger an autofocus event
        VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_TRIGGERAUTO);

        // Then restore original focus mode
        StartCoroutine(RestoreOriginalFocusMode());
    }
    
    void OnVuforiaStarted()
    {
        mHasVuforiaStarted = true;
        // Try enabling continuous autofocus
        SwitchAutofocus(true);
    }

    void OnPaused(bool paused)
    {
        var appResumed = !paused;
        if (appResumed && mHasVuforiaStarted)
        {
            // Restore original focus mode when app is resumed
            if (mIsAutofocusEnabled)
                VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_CONTINUOUSAUTO);
            else
                VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_FIXED);
        }
        else
        {
            // Set the torch flag to false on pause (because the flash torch is switched off by the OS automatically)
            mIsFlashTorchEnabled = false;
        }
    }

    IEnumerator RestoreOriginalFocusMode()
    {
        // Wait 1.5 seconds
        yield return new WaitForSeconds(1.5f);

        // Restore original focus mode
        if (mIsAutofocusEnabled)
            VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_CONTINUOUSAUTO);
        else
            VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(FocusMode.FOCUS_MODE_FIXED);
        mIsFocusing = false;
    }
}
