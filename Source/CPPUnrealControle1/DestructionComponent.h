#pragma once

#include "CoreMinimal.h" // Inclusion du fichier de base pour les classes Unreal
#include "Components/ActorComponent.h" // Inclusion du composant de base pour tous les composants d'acteurs
#include "Camera/CameraComponent.h" // Inclusion de la classe CameraComponent pour obtenir la position et l'orientation de la cam�ra
#include "Destructible.h" // Inclusion de l'interface IDestructible pour manipuler des objets destructibles
#include "DestructionComponent.generated.h" // G�n�ration des m�tadonn�es n�cessaires pour Unreal Engine

// D�claration de la classe UDestructionComponent h�ritant de UActorComponent, un composant d'acteur Unreal
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CPPUNREALCONTROLE1_API UDestructionComponent : public UActorComponent
{
	GENERATED_BODY() // Macro n�cessaire pour g�n�rer les fonctionnalit�s du syst�me Unreal (Reflection, etc.)

public:
	// Constructeur de la classe
	UDestructionComponent();

protected:
	// Cette fonction est appel�e lorsque le jeu commence ou que le composant est initialis�
	virtual void BeginPlay() override;

public:
	// Cette fonction est appel�e chaque frame pour effectuer les op�rations du composant
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Fonction publique pour lancer le rayon de destruction
	UFUNCTION(BlueprintCallable) // Permet d'appeler cette fonction depuis les Blueprints
	void DestructionBeam();

	// Fonction priv�e pour effectuer la d�tection du rayon
	void DestructionDetection();

private:
	// Propri�t�s priv�es de la classe
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destruction Component", meta = (AllowPrivateAccess = "true"))
	float m_Range; // Plage du rayon de destruction (�ditable dans l'�diteur)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destruction Component", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* m_Camera; // R�f�rence � la cam�ra, pour savoir d'o� provient le rayon de destruction

	// R�f�rence � un acteur destructible touch� par le rayon
	AActor* m_Destructible;
};
