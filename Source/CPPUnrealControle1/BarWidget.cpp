#include "BarWidget.h"
#include "Components/ProgressBar.h" // Inclusion pour accéder à la ProgressBar

void UBarWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // Vérifiez si le ProgressBar est bien assigné
    if (ProgressBar)
    {
        // Par exemple, vous pouvez définir une valeur initiale de la ProgressBar ici
        ProgressBar->SetPercent(0.5f);  // Définit la barre à 50%
    }
}

void UBarWidget::SetPercent(float Percent)
{
}
