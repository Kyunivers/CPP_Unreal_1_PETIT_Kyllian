#pragma once

#include "CoreMinimal.h" // Inclusion du fichier de base pour les classes Unreal
#include "Components/ActorComponent.h" // Inclusion du composant de base pour tous les composants d'acteurs
#include "Camera/CameraComponent.h" // Inclusion de la classe CameraComponent pour obtenir la position et l'orientation de la caméra
#include "Destructible.h" // Inclusion de l'interface IDestructible pour manipuler des objets destructibles
#include "DestructionComponent.generated.h" // Génération des métadonnées nécessaires pour Unreal Engine

// Déclaration de la classe UDestructionComponent héritant de UActorComponent, un composant d'acteur Unreal
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CPPUNREALCONTROLE1_API UDestructionComponent : public UActorComponent
{
	GENERATED_BODY() // Macro nécessaire pour générer les fonctionnalités du système Unreal (Reflection, etc.)

public:
	// Constructeur de la classe
	UDestructionComponent();

protected:
	// Cette fonction est appelée lorsque le jeu commence ou que le composant est initialisé
	virtual void BeginPlay() override;

public:
	// Cette fonction est appelée chaque frame pour effectuer les opérations du composant
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Fonction publique pour lancer le rayon de destruction
	UFUNCTION(BlueprintCallable) // Permet d'appeler cette fonction depuis les Blueprints
	void DestructionBeam();

	// Fonction privée pour effectuer la détection du rayon
	void DestructionDetection();

private:
	// Propriétés privées de la classe
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destruction Component", meta = (AllowPrivateAccess = "true"))
	float m_Range; // Plage du rayon de destruction (éditable dans l'éditeur)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destruction Component", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* m_Camera; // Référence à la caméra, pour savoir d'où provient le rayon de destruction

	// Référence à un acteur destructible touché par le rayon
	AActor* m_Destructible;
};
