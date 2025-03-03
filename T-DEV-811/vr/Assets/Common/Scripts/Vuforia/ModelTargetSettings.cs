/*==============================================================================
Copyright (c) 2021 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
==============================================================================*/

using System.Linq;
using UnityEngine;
using Vuforia;

public class ModelTargetSettings : MonoBehaviour
{
    public DeviceObserverSettings DeviceObserverSettings;

    public void ToggleStaticDT(bool enable)
    {
        // we need to disable and re-enable all potentially tracked targets so that the new device tracker instance
        // again knows about those tracked targets (information is propagated upon target activate)
        var targets = FindObjectsOfType<ScalableDataSetTrackableBehaviour>()
            .Where(m => m.enabled)
            .ToList();
        foreach (var target in targets)
        {
            target.enabled = false;
        }

        if (!DeviceObserverSettings.ToggleStaticDeviceTracker(enable))
        {
            VLog.Log("red", "Unable to set the Device Tracker Static to " + enable);
        }

        foreach (var target in targets)
        {
            target.enabled = true;
        }
    }

    public void ResetModelTargets()
    {
        foreach (var modelTarget in VuforiaBehaviour.Instance.World.GetObserverBehaviours<ModelTargetBehaviour>())
        {
            if (modelTarget.enabled)
                modelTarget.Reset();
        }

    }
}
