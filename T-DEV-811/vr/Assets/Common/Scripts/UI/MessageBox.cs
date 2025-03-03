/*============================================================================== 
Copyright (c) 2018 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.   
==============================================================================*/

using System;
using UnityEngine;
using UnityEngine.UI;

public class MessageBox : MonoBehaviour
{
    Text[] mTextComponents;
    delegate void DelegateMessageBoxButtonAction();
    DelegateMessageBoxButtonAction mDelegateMessageBoxAction;

    const string RESOURCES_MESSAGE_BOX_PREFAB_NAME = "MessageBox";
    
    public static void DisplayMessageBox(string title, string body, bool dismissable, Action dismissAction)
    {
        var prefab = (GameObject)Resources.Load(RESOURCES_MESSAGE_BOX_PREFAB_NAME);
        if (prefab)
        {
            var messageBox = Instantiate(prefab.GetComponent<MessageBox>());
            messageBox.Setup(title, body, dismissable, dismissAction);
        }
    }

    public void MessageBoxButton()
    {
        // This method called by the UI Canvas Button
        if (mDelegateMessageBoxAction != null)
            mDelegateMessageBoxAction();

        // Destroy MessageBox
        Destroy(gameObject);
    }

    void Setup(string title, string body, bool dismissable = true, Action closeButton = null)
    {
        mTextComponents = GetComponentsInChildren<Text>();

        if (mTextComponents.Length >= 2)
        {
            mTextComponents[0].text = title;
            mTextComponents[1].text = body;
        }

        if (closeButton != null)
            mDelegateMessageBoxAction = new DelegateMessageBoxButtonAction(closeButton);

        var button = GetComponentInChildren<Button>();
        if (button != null)
            button.gameObject.SetActive(dismissable);
    }
}
