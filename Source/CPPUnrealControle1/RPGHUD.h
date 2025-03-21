


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BarWidget.h"
#include "RPGHUD.generated.h"

UCLASS()
class CPPUNREALCONTROLE1_API ARPGHUD : public AHUD
{
    GENERATED_BODY()

public:
    // Constructeur
    ARPGHUD();

protected:
    // Fonction appel�e au d�but du jeu
    virtual void BeginPlay() override;  // V�rifiez que vous avez bien "override" ici

public:
    // Fonction permettant de mettre � jour le pourcentage du BarWidget
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void SetPercent(const float& Percent);

private:
    // R�f�rence � BarWidget
    UPROPERTY()
    UBarWidget* BarWidgetInstance;

    // R�f�rence au prefab BarWidget (�ditable dans l'�diteur)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<UUserWidget> BarWidgetClass;
};