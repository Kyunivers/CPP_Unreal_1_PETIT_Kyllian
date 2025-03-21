


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
    // Fonction appelée au début du jeu
    virtual void BeginPlay() override;  // Vérifiez que vous avez bien "override" ici

public:
    // Fonction permettant de mettre à jour le pourcentage du BarWidget
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void SetPercent(const float& Percent);

private:
    // Référence à BarWidget
    UPROPERTY()
    UBarWidget* BarWidgetInstance;

    // Référence au prefab BarWidget (éditable dans l'éditeur)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<UUserWidget> BarWidgetClass;
};