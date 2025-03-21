#include "BarWidget.h"
#include "Components/ProgressBar.h" // Inclusion pour acc�der � la ProgressBar

void UBarWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // V�rifiez si le ProgressBar est bien assign�
    if (ProgressBar)
    {
        // Par exemple, vous pouvez d�finir une valeur initiale de la ProgressBar ici
        ProgressBar->SetPercent(0.5f);  // D�finit la barre � 50%
    }
}

void UBarWidget::SetPercent(float Percent)
{
}
