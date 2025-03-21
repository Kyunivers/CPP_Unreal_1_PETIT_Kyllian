

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h" // Inclusion de la classe ProgressBar
#include "BarWidget.generated.h"

// Déclare la classe BarWidget qui hérite de UUserWidget
UCLASS()
class CPPUNREALCONTROLE1_API UBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Fonction appelée lors de la construction du widget
	virtual void NativeConstruct() override;

protected:
	// Variable pour stocker la ProgressBar (elle sera référencée dans l'éditeur)
	UPROPERTY(meta = (BindWidget))
	UProgressBar* ProgressBar;

public:
	// Fonction publique pour mettre à jour le pourcentage de la progress bar
	UFUNCTION(BlueprintCallable, Category = "Progress Bar")
	void SetPercent(float Percent);

};

