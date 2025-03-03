/*===============================================================================
Copyright (c) 2015-2021 PTC Inc. All Rights Reserved.

Copyright (c) 2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/

using UnityEngine;
using Vuforia;
using System.Timers;

public class DeviceObserverSettings : MonoBehaviour
{
    bool mIsDeviceObserverEnabled;
    Timer mRelocalizationStatusDelayTimer;
    Timer mResetDeviceObserverTimer;

    void Awake()
    {
        mIsDeviceObserverEnabled = VuforiaConfiguration.Instance.DeviceTracker.AutoInitAndStartTracker;
    }

    void Start()
    {
        var devicePoseBehaviour = VuforiaBehaviour.Instance.DevicePoseBehaviour;
        mIsDeviceObserverEnabled = devicePoseBehaviour.enabled;
        devicePoseBehaviour.OnTargetStatusChanged += OnDevicePoseStatusChanged;

        // Setup a timer to have short delay before processing RELOCALIZING status
        mRelocalizationStatusDelayTimer = new Timer(1000);
        mRelocalizationStatusDelayTimer.Elapsed += RelocalizingStatusDelay;
        mRelocalizationStatusDelayTimer.AutoReset = false;

        // Setup a timer to restart the DeviceTracker if tracking does not receive
        // status change from StatusInfo.RELOCALIZATION after 10 seconds.
        mResetDeviceObserverTimer = new Timer(10000);
        mResetDeviceObserverTimer.Elapsed += ResetObservation;
        mResetDeviceObserverTimer.AutoReset = false;
    }

    void OnDestroy()
    {
        if (VuforiaBehaviour.Instance != null)
            VuforiaBehaviour.Instance.DevicePoseBehaviour.OnTargetStatusChanged -= OnDevicePoseStatusChanged;
    }

    void OnDevicePoseStatusChanged(ObserverBehaviour behaviour, TargetStatus targetStatus)
    {
        var statusInfo = targetStatus.StatusInfo;

        if (statusInfo == StatusInfo.RELOCALIZING)
        {
            // If the status is Relocalizing, then start the timer if it isn't active
            if (!mRelocalizationStatusDelayTimer.Enabled)
                mRelocalizationStatusDelayTimer.Start();
        }
        else
        {
            // If the status is not Relocalizing, then stop the timers if they are active
            if (mRelocalizationStatusDelayTimer.Enabled)
                mRelocalizationStatusDelayTimer.Stop();

            if (mResetDeviceObserverTimer.Enabled)
                mResetDeviceObserverTimer.Stop();

            // Clear the status message
            StatusMessage.Display(string.Empty);
        }
    }

    // This is a C# delegate method for the Timer:
    // ElapsedEventHandler(object sender, ElapsedEventArgs e)
    void RelocalizingStatusDelay(System.Object source, ElapsedEventArgs elapsedEventArguments)
    {
        StatusMessage.Display("Point back to previously seen area and rescan to relocalize.");

        if (!mResetDeviceObserverTimer.Enabled)
            mResetDeviceObserverTimer.Start();
    }

    // This is a C# delegate method for the Timer:
    // ElapsedEventHandler(object sender, ElapsedEventArgs e)
    void ResetObservation(System.Object source, ElapsedEventArgs e)
    {
        var devicePoseBehaviour = VuforiaBehaviour.Instance.DevicePoseBehaviour;
        if (!devicePoseBehaviour.enabled)
            return;
        devicePoseBehaviour.Reset();
    }

    public bool IsDeviceObserverEnabled()
    {
        return mIsDeviceObserverEnabled;
    }

    public virtual void ToggleDeviceObserver(bool enableDeviceTracking)
    {
        var devicePoseBehaviour = VuforiaBehaviour.Instance.DevicePoseBehaviour;
        devicePoseBehaviour.enabled = enableDeviceTracking;
        mIsDeviceObserverEnabled = enableDeviceTracking;
    }

    public bool IsStaticDeviceTrackerEnabled()
    {
        var devicePoseBehaviour = VuforiaBehaviour.Instance.DevicePoseBehaviour;
        return devicePoseBehaviour.StaticMode;
    }

    public bool ToggleStaticDeviceTracker(bool enableStaticDt)
    {
        var prevEnabled = VuforiaBehaviour.Instance.enabled;
        VuforiaBehaviour.Instance.enabled = false;
        
        var devicePoseBehaviour = VuforiaBehaviour.Instance.DevicePoseBehaviour;
        var result =  devicePoseBehaviour.SetStaticMode(enableStaticDt);
        
        VuforiaBehaviour.Instance.enabled = prevEnabled;
        return result;
    }

    public void ResetDeviceObserver()
    {
        VuforiaBehaviour.Instance.DevicePoseBehaviour.Reset();
    }
}
