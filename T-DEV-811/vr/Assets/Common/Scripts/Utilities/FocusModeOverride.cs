/*===============================================================================
Copyright (c) 2022 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/

using System;
using UnityEngine;
using Vuforia;

/// <summary>
/// This behaviour overrides the Focus Mode from the Vuforia Configuration.
/// </summary>
public class FocusModeOverride : MonoBehaviour
{
    [SerializeField] public Vuforia.FocusMode Focus = FocusMode.FOCUS_MODE_MACRO;

    void Awake()
    {
        try
        {
            if (!VuforiaBehaviour.Instance.CameraDevice.SetFocusMode(Focus))
            {
                Debug.LogWarning($"Failed to set Focus Mode to {Focus}!");
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e);
        }
    }
}