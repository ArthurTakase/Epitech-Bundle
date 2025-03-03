using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

public class ActiveIcon : MonoBehaviour
{
    public List<Image> icons = new();
    private int currentIndex = 0;

    public void SetActiveIcon(int index)
    {
        if (index < 0 || index >= icons.Count) return;

        Vibration.VibratePop();

        icons[currentIndex].color = new Color32(255, 255, 255, 180);
        icons[index].color = new Color32(255, 255, 255, 255);
        currentIndex = index;
    }
}