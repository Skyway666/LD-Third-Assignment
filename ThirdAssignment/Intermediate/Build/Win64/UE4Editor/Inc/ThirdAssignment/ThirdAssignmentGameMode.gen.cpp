// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThirdAssignment/ThirdAssignmentGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThirdAssignmentGameMode() {}
// Cross Module References
	THIRDASSIGNMENT_API UClass* Z_Construct_UClass_AThirdAssignmentGameMode_NoRegister();
	THIRDASSIGNMENT_API UClass* Z_Construct_UClass_AThirdAssignmentGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ThirdAssignment();
// End Cross Module References
	void AThirdAssignmentGameMode::StaticRegisterNativesAThirdAssignmentGameMode()
	{
	}
	UClass* Z_Construct_UClass_AThirdAssignmentGameMode_NoRegister()
	{
		return AThirdAssignmentGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AThirdAssignmentGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AThirdAssignmentGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ThirdAssignment,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AThirdAssignmentGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ThirdAssignmentGameMode.h" },
		{ "ModuleRelativePath", "ThirdAssignmentGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AThirdAssignmentGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThirdAssignmentGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AThirdAssignmentGameMode_Statics::ClassParams = {
		&AThirdAssignmentGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AThirdAssignmentGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AThirdAssignmentGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AThirdAssignmentGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AThirdAssignmentGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AThirdAssignmentGameMode, 4111748972);
	template<> THIRDASSIGNMENT_API UClass* StaticClass<AThirdAssignmentGameMode>()
	{
		return AThirdAssignmentGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AThirdAssignmentGameMode(Z_Construct_UClass_AThirdAssignmentGameMode, &AThirdAssignmentGameMode::StaticClass, TEXT("/Script/ThirdAssignment"), TEXT("AThirdAssignmentGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AThirdAssignmentGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
