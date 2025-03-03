/*===============================================================================
Copyright (c) 2022 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/

using System;
using UnityEngine;
using Vuforia;

/// <summary>
/// This behaviour overrides the Camera Mode from the Vuforia Configuration.
/// </summary>
public class CameraModeOverride : MonoBehaviour
{
    [SerializeField] public CameraMode CameraMode = CameraMode.MODE_OPTIMIZE_QUALITY;
    
    void Awake()
    {
        try
        {
            if (!VuforiaBehaviour.Instance.CameraDevice.SetCameraMode(CameraMode))
            {
                Debug.LogWarning($"Failed to set Camera Mode to {CameraMode}!");
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e);
        }
    }

    void OnVuforiaInitialized()
    {
        
    }
}