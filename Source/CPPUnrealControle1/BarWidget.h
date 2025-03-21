

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h" // Inclusion de la classe ProgressBar
#include "BarWidget.generated.h"

// D�clare la classe BarWidget qui h�rite de UUserWidget
UCLASS()
class CPPUNREALCONTROLE1_API UBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Fonction appel�e lors de la construction du widget
	virtual void NativeConstruct() override;

protected:
	// Variable pour stocker la ProgressBar (elle sera r�f�renc�e dans l'�diteur)
	UPROPERTY(meta = (BindWidget))
	UProgressBar* ProgressBar;

public:
	// Fonction publique pour mettre � jour le pourcentage de la progress bar
	UFUNCTION(BlueprintCallable, Category = "Progress Bar")
	void SetPercent(float Percent);

};

