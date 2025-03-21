#include "RPGHUD.h"
#include "BarWidget.h"

ARPGHUD::ARPGHUD()
{
	// Constructeur
}

void ARPGHUD::BeginPlay()
{
	Super::BeginPlay();

	// Cr�er le widget BarWidget et l'ajouter au viewport
	if (BarWidgetClass)
	{
		BarWidgetInstance = CreateWidget<UBarWidget>(GetWorld(), BarWidgetClass);
		if (BarWidgetInstance)
		{
			BarWidgetInstance->AddToViewport();
		}
	}
}

void ARPGHUD::SetPercent(const float& Percent)
{
	if (BarWidgetInstance)
	{
		BarWidgetInstance->SetPercent(Percent); // Met � jour le pourcentage dans le widget
	}
}
