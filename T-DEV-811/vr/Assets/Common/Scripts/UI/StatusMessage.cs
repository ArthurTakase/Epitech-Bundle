/*===============================================================================
Copyright (c) 2019 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/

using System;
using System.Collections;
using UnityEngine;
using UnityEngine.UI;

public class StatusMessage : MonoBehaviour
{
    static StatusMessage sStatusMessage;    
    static bool sIsDestroyed;
    
    CanvasGroup mCanvasGroup;
    Text mMessage;
    bool mInitialized;
    Coroutine mCoroutine;
    
    /// <returns>The instance or possibly null.</returns>
    static StatusMessage Instance
    {
        get
        {
            if (sIsDestroyed)
                return null;
            
            if (sStatusMessage != null)
                return sStatusMessage;
            
            var prefab = (GameObject)Resources.Load("StatusMessage");
            if (!prefab)
                return null;
            
            sStatusMessage = Instantiate(prefab.GetComponent<StatusMessage>());
            sStatusMessage.Init();
            return sStatusMessage;
        }
    }
    
    void Init()
    {
        if (mInitialized)
            return;
        
        mCanvasGroup = GetComponentInChildren<CanvasGroup>();
        mCanvasGroup.alpha = 0;
        mMessage = GetComponentInChildren<Text>();
        mMessage.text = "";
        mInitialized = true;
        var root = transform.GetChild(0).GetComponent<RectTransform>();
        var safeAreaManager = FindObjectOfType<SafeAreaManager>();
        if (safeAreaManager)
        {
            safeAreaManager.AddSafeAreaRect(root, true, false);
        }
    }
    
    protected virtual void OnDestroy()
    {
        sIsDestroyed = true;
    }

    public static void Display(string message, bool fadeOut = false)
    {
        if (Instance == null)
        {
            return;
        }

        // Check to see if there's an existing message first (i.e. Length > 0).
        // Return if the new message is a fadeOut message, otherwise overwrite.
        // Rule: Don't overwrite a non-fadeOut message with a fadeOut one.
        if (Instance.mMessage.text.Length > 0 && fadeOut)
        {
            return;
        }
        
        if (Instance.mCoroutine != null)
        {
            Instance.StopCoroutine(Instance.mCoroutine);
            Instance.mCoroutine = null;
        }
        
        Instance.mMessage.text = message;
        
        if (fadeOut)
        {
            Instance.mCanvasGroup.alpha = 1;
            Instance.mCoroutine = Instance.StartCoroutine(Instance.FadeOut());
        }
        else
            Instance.mCanvasGroup.alpha = (message.Length > 0) ? 1 : 0;
    }

    IEnumerator FadeOut()
    {
        yield return new WaitForSeconds(1f);
        
        for (float f = 1f; f >= 0; f -= 0.1f)
        {
            f = (float)Math.Round(f, 1);
            mCanvasGroup.alpha = (float)Math.Round(f, 1);
            yield return null;
        }
        // clear message
        mMessage.text = "";
    }
}
