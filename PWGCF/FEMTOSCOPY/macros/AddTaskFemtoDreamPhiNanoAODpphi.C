AliAnalysisTaskSE *AddTaskFemtoDreamPhiNanoAODpphi(bool isMC = false,
                                               TString CentEst = "kInt7",
                                               const char *cutVariation = "0") {
  TString suffix = TString::Format("%s", cutVariation);

  AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();

  if (!mgr) {
    printf("No analysis manager to connect to!\n");
    return nullptr;
  }
  if (!mgr->GetInputEventHandler()) {
    printf("This task requires an input event handler!\n");
    return nullptr;
  }

  AliFemtoDreamEventCuts *evtCuts = AliFemtoDreamEventCuts::StandardCutsRun2();
  evtCuts->CleanUpMult(false, false, false, true);
  evtCuts->SetSphericityCuts(0.7, 1);

  // Proton cuts
  const float ProtonPtlow = 0.425;
  const float ProtonPtup = 0.575;
  const float ProtonEtaLow = 0.75;
  const float ProtonEtaUp = 0.85;
  const float ProtonNsigmaLow = 2.5;
  const float ProtonNsigmaUp = 3.5;
  const float ProtonNClsLow = 70;
  const float ProtonNClsUp = 90;

  AliFemtoDreamTrackCuts *TrackCuts =
      AliFemtoDreamTrackCuts::PrimProtonCuts(isMC, true, false, false);
  TrackCuts->SetCutCharge(1);

  AliFemtoDreamTrackCuts *AntiTrackCuts =
      AliFemtoDreamTrackCuts::PrimProtonCuts(isMC, true, false, false);
  AntiTrackCuts->SetCutCharge(-1);

  if (suffix != "0" && suffix != "999") {
    TrackCuts->SetMinimalBooking(true);
    AntiTrackCuts->SetMinimalBooking(true);
  }

  if (suffix == "1") {
    TrackCuts->SetPtRange(ProtonPtlow, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtlow, 4.05);
    TrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    AntiTrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
  } else if (suffix == "2") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
  } else if (suffix == "3") {
    TrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    AntiTrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    TrackCuts->SetNClsTPC(ProtonNClsUp);
    AntiTrackCuts->SetNClsTPC(ProtonNClsUp);
  } else if (suffix == "4") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
  } else if (suffix == "5") {
    TrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
    AntiTrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
    TrackCuts->SetNClsTPC(ProtonNClsLow);
    AntiTrackCuts->SetNClsTPC(ProtonNClsLow);
  } else if (suffix == "6") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
  } else if (suffix == "7") {
    TrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    AntiTrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    TrackCuts->SetNClsTPC(ProtonNClsLow);
    AntiTrackCuts->SetNClsTPC(ProtonNClsLow);
  } else if (suffix == "8") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
  } else if (suffix == "9") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetNClsTPC(ProtonNClsUp);
    AntiTrackCuts->SetNClsTPC(ProtonNClsUp);
  } else if (suffix == "10") {
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    TrackCuts->SetNClsTPC(ProtonNClsLow);
    AntiTrackCuts->SetNClsTPC(ProtonNClsLow);
  } else if (suffix == "11") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
  } else if (suffix == "12") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetNClsTPC(ProtonNClsUp);
    AntiTrackCuts->SetNClsTPC(ProtonNClsUp);
  } else if (suffix == "13") {
    TrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    AntiTrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    TrackCuts->SetPtRange(ProtonPtlow, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtlow, 4.05);
  } else if (suffix == "14") {
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    TrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
    AntiTrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
  } else if (suffix == "15") {
    TrackCuts->SetNClsTPC(ProtonNClsUp);
    AntiTrackCuts->SetNClsTPC(ProtonNClsUp);
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
  } else if (suffix == "16") {
    TrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
    AntiTrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
  } else if (suffix == "17") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetNClsTPC(ProtonNClsLow);
    AntiTrackCuts->SetNClsTPC(ProtonNClsLow);
  } else if (suffix == "18") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
  } else if (suffix == "19") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
  } else if (suffix == "20") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
  } else if (suffix == "21") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetNClsTPC(ProtonNClsLow);
    AntiTrackCuts->SetNClsTPC(ProtonNClsLow);
  } else if (suffix == "22") {
    TrackCuts->SetPtRange(ProtonPtup, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtup, 4.05);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaLow);
  } else if (suffix == "23") {
    TrackCuts->SetPtRange(ProtonPtlow, 4.05);
    AntiTrackCuts->SetPtRange(ProtonPtlow, 4.05);
    TrackCuts->SetNClsTPC(ProtonNClsUp);
    AntiTrackCuts->SetNClsTPC(ProtonNClsUp);
  } else if (suffix == "24") {
    TrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
    AntiTrackCuts->SetEtaRange(-ProtonEtaLow, ProtonEtaLow);
    TrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
    AntiTrackCuts->SetPID(AliPID::kProton, 0.75, ProtonNsigmaUp);
  } else if (suffix == "25") {
    TrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    AntiTrackCuts->SetEtaRange(-ProtonEtaUp, ProtonEtaUp);
    TrackCuts->SetNClsTPC(ProtonNClsLow);
    AntiTrackCuts->SetNClsTPC(ProtonNClsLow);
  }



  // Kaon cuts
  const float KaonPtlow = 0.075;
  const float KaonPtup = 0.225;
  const float KaonEtaLow = 0.75;
  const float KaonEtaUp = 0.85;
  const float KaonNsigmaLow = 4.25;
  const float KaonNsigmaUp = 5.75;
  const float KaonNClsLow = 70;
  const float KaonNClsUp = 90;
  const float SpheriLow = 0.665;
  const float SpheriUp = 0.735;

  AliFemtoDreamTrackCuts *TrackPosKaonCuts =
      AliFemtoDreamTrackCuts::PrimKaonCuts(isMC, true, false, false);
  TrackPosKaonCuts->SetCutCharge(1);
  TrackPosKaonCuts->SetFilterBit(128);

  AliFemtoDreamTrackCuts *TrackNegKaonCuts =
      AliFemtoDreamTrackCuts::PrimKaonCuts(isMC, true, false, false);
  TrackNegKaonCuts->SetCutCharge(-1);
  TrackNegKaonCuts->SetFilterBit(128);

  TrackPosKaonCuts->SetDCAVtxZ(0.4);
  TrackNegKaonCuts->SetDCAVtxZ(0.4);
  TrackPosKaonCuts->SetDCAVtxXY(0.8);
  TrackNegKaonCuts->SetDCAVtxXY(0.8);

  if (suffix != "0" && suffix != "999") {
    TrackPosKaonCuts->SetMinimalBooking(true);
    TrackNegKaonCuts->SetMinimalBooking(true);
  }

  if (suffix == "1") {
  TrackPosKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
} else if (suffix == "2") {
  evtCuts->SetSphericityCuts(SpheriLow,1);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsLow);
} else if (suffix == "3") {
  evtCuts->SetSphericityCuts(SpheriUp,1);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
} else if (suffix == "4") {
  evtCuts->SetSphericityCuts(SpheriLow,1);
  TrackPosKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
   TrackNegKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
} else if (suffix == "5") {
  evtCuts->SetSphericityCuts(SpheriUp,1);
  TrackPosKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtlow, 999);
} else if (suffix == "6") {
  TrackPosKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackPosKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
   TrackNegKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
} else if (suffix == "7") {
  evtCuts->SetSphericityCuts(SpheriLow,1);
  TrackPosKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
} else if (suffix == "8") {
  TrackPosKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsUp);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsUp);
} else if (suffix == "9") {
  TrackPosKaonCuts->SetPtRange(KaonPtup, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtup, 999);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
} else if (suffix == "10") {
  TrackPosKaonCuts->SetPtRange(KaonPtup, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtup, 999);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
} else if (suffix == "11") {
  TrackPosKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
} else if (suffix == "12") {
  TrackPosKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
} else if (suffix == "13") {
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsLow);
} else if (suffix == "14") {
  TrackPosKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaLow);
} else if (suffix == "15") {
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsLow);
} else if (suffix == "16") {
  TrackPosKaonCuts->SetPtRange(KaonPtup, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtup, 999);
  TrackPosKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
} else if (suffix == "17") {
  TrackPosKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackPosKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtlow, 999);
} else if (suffix == "18") {
  TrackPosKaonCuts->SetPtRange(KaonPtup, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtup, 999);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsLow);
} else if (suffix == "19") {
  TrackPosKaonCuts->SetPtRange(KaonPtup, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtup, 999);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsUp);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsUp);
} else if (suffix == "20") {
  TrackPosKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackPosKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
} else if (suffix == "21") {
  TrackPosKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsLow);
} else if (suffix == "22") {
  TrackPosKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtlow, 999);
  TrackPosKaonCuts->SetNClsTPC(KaonNClsLow);
  TrackNegKaonCuts->SetNClsTPC(KaonNClsLow);
} else if (suffix == "23") {
  evtCuts->SetSphericityCuts(SpheriUp,1);
  TrackPosKaonCuts->SetPtRange(KaonPtup, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtup, 999);
  TrackPosKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
} else if (suffix == "24") {
  TrackPosKaonCuts->SetPtRange(KaonPtup, 999);
  TrackNegKaonCuts->SetPtRange(KaonPtup, 999);
  TrackPosKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaLow, KaonEtaLow);
} else if (suffix == "25") {
  TrackPosKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
  TrackNegKaonCuts->SetEtaRange(-KaonEtaUp, KaonEtaUp);
  TrackPosKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
  TrackNegKaonCuts->SetPID(AliPID::kKaon, 0.4, KaonNsigmaUp);
}


  AliFemtoDreamv0Cuts *TrackCutsPhi = new AliFemtoDreamv0Cuts();
  TrackCutsPhi->SetIsMonteCarlo(isMC);
  TrackCutsPhi->SetAxisInvMassPlots(400, 0.95, 2);
  TrackCutsPhi->SetCutInvMass(0.008);
  AliFemtoDreamTrackCuts *dummyCutsPos = new AliFemtoDreamTrackCuts();
  dummyCutsPos->SetIsMonteCarlo(isMC);
  AliFemtoDreamTrackCuts *dummyCutsNeg = new AliFemtoDreamTrackCuts();
  dummyCutsNeg->SetIsMonteCarlo(isMC);
  TrackCutsPhi->SetPosDaugterTrackCuts(dummyCutsPos);
  TrackCutsPhi->SetNegDaugterTrackCuts(dummyCutsNeg);
  TrackCutsPhi->SetPDGCodePosDaug(321);
  TrackCutsPhi->SetPDGCodeNegDaug(321);
  TrackCutsPhi->SetPDGCodev0(333);

  double Phimass = TDatabasePDG::Instance()->GetParticle(333)->Mass();

  if (suffix != "0") {
    TrackCutsPhi->SetMinimalBooking(true);
  }
//  if (suffix == "1") {
//    TrackCutsPhi->SetCutWindow(1.028+0.005, 1.044+0.005);
//  }
//  if (suffix == "2") {
//      TrackCutsPhi->SetCutWindow(1.028+0.01, 1.044+0.01);
//  }
//  if (suffix == "3") {
//      TrackCutsPhi->SetCutWindow(1.028+0.02, 1.044+0.02);
//  }


  // Now we define stuff we want for our Particle collection
  // Thanks, CINT - will not compile due to an illegal constructor
  // std::vector<int> PDGParticles ={2212,2212,3122,3122,3312,3312};
  // First we need to tell him about the particles we mix, from the
  // PDG code the mass is obtained.
  std::vector<int> PDGParticles;
  PDGParticles.push_back(2212);  // 0 protons REC MC
  PDGParticles.push_back(2212);  // 1 antiprot REC MC
  PDGParticles.push_back(333);   // 2 v0 particle REC MC
  PDGParticles.push_back(2212);  // 3 proton truth MC TRUTH
  PDGParticles.push_back(2212);  // 4 antiprot truth MC TRUTH
  PDGParticles.push_back(333);   // 5 True Phi inv mass MC TRUTH
  PDGParticles.push_back(333);   // 6 Fake Phi inv mass (combi. BG) MC TRUTHn

  // We need to set the ZVtx bins
  std::vector<float> ZVtxBins;
  ZVtxBins.push_back(-10);
  ZVtxBins.push_back(-8);
  ZVtxBins.push_back(-6);
  ZVtxBins.push_back(-4);
  ZVtxBins.push_back(-2);
  ZVtxBins.push_back(0);
  ZVtxBins.push_back(2);
  ZVtxBins.push_back(4);
  ZVtxBins.push_back(6);
  ZVtxBins.push_back(8);
  ZVtxBins.push_back(10);
  // The Multiplicity bins are set here
  std::vector<int> MultBins;
  MultBins.push_back(0);
  MultBins.push_back(4);
  MultBins.push_back(8);
  MultBins.push_back(12);
  MultBins.push_back(16);
  MultBins.push_back(20);
  MultBins.push_back(24);
  MultBins.push_back(28);
  MultBins.push_back(32);
  MultBins.push_back(36);
  MultBins.push_back(40);
  MultBins.push_back(44);
  MultBins.push_back(48);
  MultBins.push_back(52);
  MultBins.push_back(56);
  MultBins.push_back(60);
  MultBins.push_back(64);
  MultBins.push_back(68);
  MultBins.push_back(72);
  MultBins.push_back(76);
  MultBins.push_back(80);
  MultBins.push_back(84);
  MultBins.push_back(88);
  MultBins.push_back(92);
  MultBins.push_back(96);
  MultBins.push_back(100);

  // Number of bins
  std::vector<int> NBins;
  //  NBins.push_back(750);
  //  NBins.push_back(750);
  //  NBins.push_back(750);
  //  NBins.push_back(750);
  //  NBins.push_back(750);
  //  NBins.push_back(750);
  std::vector<float> kMin;
  // minimum k* value
  //  kMin.push_back(0.);
  //  kMin.push_back(0.);
  //  kMin.push_back(0.);
  //  kMin.push_back(0.);
  //  kMin.push_back(0.);
  //  kMin.push_back(0.);
  // maximum k* value
  std::vector<float> kMax;
  //  kMax.push_back(3.);
  //  kMax.push_back(3.);
  //  kMax.push_back(3.);
  //  kMax.push_back(3.);
  //  kMax.push_back(3.);
  //  kMax.push_back(3.);
  // pair QA extended
  std::vector<int> pairQA;
  //  pairQA.push_back(11); //pp
  //  pairQA.push_back(0); //pap
  //  pairQA.push_back(12); //pphi
  //  pairQA.push_back(11); //apap
  //  pairQA.push_back(12); //apphi
  //  pairQA.push_back(22); //phiphi

  for (int i = 0; i < (1 + 2 + 3 + 4 + 5 + 6 + 7); i++) {
    NBins.push_back(750);
    kMin.push_back(0.);
    kMax.push_back(3.);
    pairQA.push_back(0);
  }

  pairQA[0] = 11;   // pp
  pairQA[1] = 11;   // pap
  pairQA[2] = 12;   // pphi
  pairQA[3] = 0;
  pairQA[4] = 0;
  pairQA[5] = 0;
  pairQA[6] = 0;

  pairQA[7] = 11;   // apap
  pairQA[8] = 12;   // apphi
  pairQA[9] = 0;
  pairQA[10] = 0;
  pairQA[11] = 0;
  pairQA[12] = 0;


  pairQA[13] = 0;  // phiphi

  if (isMC) {
   for (int i=14;i<28;i++)  {
       pairQA[i] = 0;
      }
  }

  AliFemtoDreamCollConfig *config =
      new AliFemtoDreamCollConfig("Femto", "Femto");
//  config->SetPtQA(true);
//  config->SetMassQA(true);
//  config->SetmTBinning(true);
//  config->SetdPhidEtaPlots(true);
//  config->SetExtendedQAPairs(pairQA);
  config->SetZBins(ZVtxBins);
  config->SetMultBins(MultBins);
  config->SetMultBinning(true);
  config->SetPDGCodes(PDGParticles);
  config->SetNBinsHist(NBins);
  config->SetMinKRel(kMin);
  config->SetMaxKRel(kMax);
  config->SetUseEventMixing(true);
  config->SetMixingDepth(10);
//  config->SetPhiEtaBinnign(true);
  //config->SetMomentumResolution(true);

  //-------MIXED EVENTS---------------------------
  // config->SetUseEventMixing(true);
  // config->SetMixingDepth(10);

  //-------ROTATED SAMPLE-------------------------
  //  config->SetUseEventMixing(false);
  //  config->SetUsePhiSpinning(true);
  //  config->SetControlMethod(AliFemtoDreamCollConfig::kPhiSpin);
  //  config->SetSpinningDepth(1);

  //-------COMMON ANCESTORS-------------------------

//  if (isMC) {
//    config->SetAncestors(true);
//    config->GetDoAncestorsPlots();
//  }

  /*
  //This is just to show off what would be possible in case you are interested,
  don't be confused by this at the beginning
  //you can just ignore it!
  if (false) {
    config->SetkTBinning(false);
    config->SetmTBinning(false);
    config->SetkTCentralityBinning(false);
    std::vector<float> centBins;
    centBins.push_back(20);
    centBins.push_back(40);
    centBins.push_back(90);
    config->SetCentBins(centBins);
    config->SetZBins(ZVtxBins);

    if (isMC) {
      config->SetMomentumResolution(true);
    } else {
      std::cout << "You are trying to request the Momentum Resolution without MC
  Info; fix it wont work! \n";
    }
    if (isMC) {
      config->SetPhiEtaBinnign(true);
    } else {
      std::cout << "You are trying to request the Eta Phi Plots without MC Info;
  fix it wont work! \n";
    }
  }
   */
  // now we create the task
  AliAnalysisTaskNanoAODFemtoDreamPhi *task =
      new AliAnalysisTaskNanoAODFemtoDreamPhi(
          "AliAnalysisTaskNanoAODFemtoDreamPhi", isMC);
  // THIS IS VERY IMPORTANT ELSE YOU DONT PROCESS ANY EVENTS
  // kINT7 == Minimum bias
  // kHighMultV0 high multiplicity triggered by the V0 detector
  if (CentEst == "kInt7") {
    task->SetTrigger(AliVEvent::kINT7);
    task->SelectCollisionCandidates(AliVEvent::kINT7);
    std::cout << "Added kINT7 Trigger \n";
  } else if (CentEst == "kHM") {
    task->SetTrigger(AliVEvent::kHighMultV0);
    task->SelectCollisionCandidates(AliVEvent::kHighMultV0);
    std::cout << "Added kHighMultV0 Trigger \n";
  } else {
    std::cout << "============================================================="
                 "========"
              << std::endl;
    std::cout << "============================================================="
                 "========"
              << std::endl;
    std::cout << "Centrality Estimator not set, fix it else your Results will "
                 "be empty!"
              << std::endl;
    std::cout << "============================================================="
                 "========"
              << std::endl;
    std::cout << "============================================================="
                 "========"
              << std::endl;
  }

  // Throw all our settings to the task
  task->SetEventCuts(evtCuts);
  task->SetProtonCuts(TrackCuts);
  task->SetAntiProtonCuts(AntiTrackCuts);
  task->SetPosKaonCuts(TrackPosKaonCuts);
  task->SetNegKaonCuts(TrackNegKaonCuts);
  task->SetCollectionConfig(config);
  task->SetPhiCuts(TrackCutsPhi);
  task->SetOEventMixing(false);
  task->SetMCTruth(false);

//  task->SetCutWindowMCTRUTH(Phimass - 0.008, Phimass + 0.008);
//  task->SetmixREC(true);
//  task->SetMCTruth(true);
//  task->SetmixTRUTHREAL(true);
//  task->SetmixTRUTFAKE(true);
//  task->SetpTprotonMCTRUTH(0.5);
//  task->SetetaprotonMCTRUTH(0.8);
//  task->SetpTkaonMCTRUTH(0.15);
//  task->SetetakaonMCTRUTH(0.8);


//  if (suffix == "0") {
//      task->SetCutWindowMCTRUTH(Phimass - 0.008, Phimass + 0.008);
//      config->SetPtQA(true);
//      config->SetMassQA(true);
//      config->SetmTBinning(true);
//      config->SetdPhidEtaPlots(true);
//      config->SetExtendedQAPairs(pairQA);
//      task->SetmixREC(true);
//      task->SetmixTRUTHREAL(true);
//      task->SetmixTRUTFAKE(true);
//  }
//    if (suffix == "1") {
//        task->SetCutWindowMCTRUTH(0.995, 1.011);
//        TrackCutsPhi->SetMinimalBooking(true);
//        task->SetmixREC(true);
//        task->SetmixTRUTHREAL(true);
//        task->SetmixTRUTFAKE(true);
//    }
//    if (suffix == "2") {
//        task->SetCutWindowMCTRUTH(1.028, 1.044);
//        TrackCutsPhi->SetMinimalBooking(true);
//        task->SetmixREC(true);
//        task->SetmixTRUTHREAL(true);
//        task->SetmixTRUTFAKE(true);
//    }



  mgr->AddTask(task);

  TString file = AliAnalysisManager::GetCommonFileName();

  AliAnalysisDataContainer *cinput = mgr->GetCommonInputContainer();

  mgr->ConnectInput(task, 0, cinput);

  AliAnalysisDataContainer *coutputQA;
  TString addon = "";
  if (CentEst == "kInt7") {
    addon += "MB";
  } else if (CentEst == "kHM") {
    addon += "HM";
  }
  TString QAName = Form("%sPhiResults%s", addon.Data(), suffix.Data());
  coutputQA = mgr->CreateContainer(QAName.Data(), TList::Class(),
                                   AliAnalysisManager::kOutputContainer,
                                   Form("%s:%s", file.Data(), QAName.Data()));
  mgr->ConnectOutput(task, 1, coutputQA);

  return task;
}
