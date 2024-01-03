#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/* The Earth-Moon-Mars Radiation Environment Module (EMMREM) software is */
/* free software; you can redistribute and/or modify the EMMREM sotware */
/* or any part of the EMMREM software under the terms of the GNU General */
/* Public License (GPL) as published by the Free Software Foundation; */
/* either version 2 of the License, or (at your option) any later */
/* version. Software that uses any portion of the EMMREM software must */
/* also be released under the GNU GPL license (version 2 of the GNU GPL */
/* license or a later version). A copy of this GNU General Public License */
/* may be obtained by writing to the Free Software Foundation, Inc., 59 */
/* Temple Place, Suite 330, Boston MA 02111-1307 USA or by viewing the */
/* license online at http://www.gnu.org/copyleft/gpl.html. */

#include <libconfig.h>
#include "cubeShellStruct.h"

typedef struct /* Config_t */ {

  // NOTE:
  // The config parameter descriptions found here are taken from
  // the EPREM Manual from Jan 2, 2018 and from the example template file with minor changes.
  //
  // These descriptions should apply to the parameters as they appear IN CODE,
  // not as they are specified in the .ini config files. These are different, yes. This is bad, yes.
  // See `tDel` for example: config file specifies it in days, but the code uses transformed `tDel` in AU/c.
  // If I mixed up units of some of the parameters because of the above: 1. I'm sorry; 2. please fix it.
  //
  // Some descriptions might be incomplete. Not every parameter seems to be documented.
  // Disable line soft-wrapping if you don't want to go insane reading this.


  // Grid Parameters:

  Index_t  numNodesPerStream;  // Number of nodes in the grid along each stream
  Index_t  numRowsPerFace;     // Number of rows of streams per face for 6 faces
  Index_t  numColumnsPerFace;  // Number of columns of streams per face for 6 faces
  Index_t  numEnergySteps;     // Number of energy steps (TODO: How are they spaced?)
  Index_t  numMuSteps;         // Number of pitch-angle steps. These are in cosine PA space and are spaced so that each step covers the same fraction of the unit sphere.


  // Core Simulation Parameters:

  Scalar_t  rScale;         // Location of the inner boundary (AU)
  Scalar_t  flowMag;        // Flow velocity of background constant solar wind (cm/s)
  Scalar_t  mhdDensityAu;   // Number density (cm^-3) at 1 AU
  Scalar_t  mhdBAu;         // Magnetic field (Gauss) at 1 AU
  Scalar_t  simStartTime;   // Simulation start time in fractional days. This only affects the JD label of the time axis; it is a tag for when it starts, so the output can be labeled with the desired day.
  Scalar_t  simStopTime;    // Simulation stop time in fractional days.
  Scalar_t  tDel;           // Relaxation time-step in AU/c (or approximately 8 min). The default of 7.21436 is about 1 hour. This is the main "outer" time step.
  Index_t   numEpSteps;     // Number of ep-solver substeps, the number of times energetic particle distribution function is updated between updates to MHD/node flow. Affects numerical stability; 20 seems to be about right.
  Scalar_t  aziSunStart;    // Initial azimuth of the Sun's surface (radians)
  Scalar_t  omegaSun;       // Solar rotation rate (radians/AU/c)
  Scalar_t  lamo;           // MFP (Mean Free Path) in AU at 1AU and 1GV.
  Scalar_t  dsh_min;        // Minimal distance (AU?) between shell nodes in parallel diffusion (depends on useParallelDiffusion). Nodes that are closer together than this value will be "deduplicated".
  Scalar_t  dsh_hel_min;    // (Unused)
  Scalar_t  mfpRadialPower;
  Scalar_t  rigidityPower;  // Exponent for rigidity scaling (mfp scaling with rigidity?)

  Scalar_t  kperxkpar;      // Efficiency of perpendicular diffusion (Kper/Kpar)

  Scalar_t  eMin;           // Minimum energy fully modeled in the code (MeV/nuc)
  Scalar_t  eMax;           // Maximum energy (MeV/nuc)
  Scalar_t  gammaEhigh;     // (Unused) Negative slope of f at the upper energy boundary
  Scalar_t  gammaElow;      // (Unused) Negative slope of f at the lower energy boundary. Because quantities in the energetic particle solver depend on derivatives of the distribution function, the slope at the smallest/largest energy bin (eMin/eMax) needs to be assumed

  Index_t   checkSeedPopulation; // Floor/Reset distribution if it drops below background, (TODO: only on inner three nodes of each streamline?)


  // Drift/Diffusion:

  Index_t    useShellDiffusion;    // Use perpendicular diffusion
  Index_t    useParallelDiffusion; // Use parallel diffusion. (TODO: Otherwise energetic particles will just flow into the domain with the plasma/never move node to node? Set mfp to 0?)
  Index_t    useDrift;             // Use particle drifts (TODO: Allow parallel diffusion?)


  // Adiabatic Change/Focusing:

  Index_t    useAdiabaticChange; // Use adiabatic change (TODO: presumably in energy, as expands?)
  Index_t    useAdiabaticFocus;  // Use adiabatic focusing (change in PA as field decreases)
  Index_t    adiabaticChangeAlg; // Select an algorithm for adiabatic change (from 1 to 3) (Used to init the global AdiabaticChangeAlg constant)
  Index_t    adiabaticFocusAlg;  // Select an algorithm for adiabatic focusing (from 1 to 3) (Used to init the global AdiabaticFocusAlg constant)
  Index_t    useStochastic;      // (Unused)
  Scalar_t   focusingLimit;      // (Unused)


  // Manual Stream Spawn:

  int useManualStreamSpawnLoc; // Specify initial stream locations manually
  Scalar_t* streamSpawnLocAzi; // Manual initial stream azimuth (phi), radians
  Scalar_t* streamSpawnLocZen; // Manual initial stream zenith (theta), radians


  // Particle Species:

  int numSpecies;      // Number of particle species (length needs to match arrays below)
  Scalar_t*  mass;     // Masses in nucleons (length needs to be eq to numSpecies)
  Scalar_t*  charge;   // Charges (e-) (length needs to be eq to numSpecies)


  // Point Observers:

  int numObservers;    // Number of point observers (needs to match the dimension of arrays below or be 0)
  Scalar_t*  obsR;     // Observer radial position, in AU
  Scalar_t*  obsTheta; // Observer colatitude (radians)
  Scalar_t*  obsPhi;   // Observer longitude, (radians, 0.0 is center of face zero)
  Scalar_t idw_p;      // Weighting factor for point-observer interpolation. The power is applied to the distance from the observer to the modeled point, for interpolation. Higher power more heavily weights closer nodes.


  // Coupled MHD:

  Index_t mhdCouple;
  Index_t mhdNumFiles;
  Index_t useMhdSteadyStateDt;
  Index_t mhdSteadyState;
  char* mhdDirectory;
  Index_t mhdDigits;

  Index_t mhdCoupledTime;
  Scalar_t mhdStartTime;
  Scalar_t epEquilibriumCalcDuration; // Relaxation time in fractional days. The energetic particle code will be run for this length of time (against time step 0 of hte MHD?) before starting the simulation, in the hopes of reaching a steady state. This usually doesn't work out well and is rarely used

  Scalar_t preEruptionDuration;
  Index_t mhdInitMonteCarlo;
  Index_t mhdInitFromOuterBoundary;
  Scalar_t mhdInitRadius;
  Scalar_t mhdInitTimeStep;

  Scalar_t mhdRadialMin;
  Scalar_t mhdRadialMax;
  Scalar_t mhdVmin;

  Scalar_t parallelFlow;
  Index_t  fieldAligned;

  Scalar_t epCalcStartTime;

  Index_t mhdRotateSolution;

  Scalar_t mhdBConvert;
  Scalar_t mhdVConvert;
  Scalar_t mhdRhoConvert;
  Scalar_t mhdTimeConvert;

  Index_t subTimeCouple;  // (Unused) Couple to the MHD/plasma on the sub-timesteps


  // Solar Energetic Particle Source Function Parameters:
  //
  // This is a source function that is used as a floor on the energetic particle
  // distribution for the innermost three nodes on each streamline.
  // (This set of nodes is sometimes referred to as a "shell", i.e. this function
  // applies on the innermost three shells, but "shell" is also used to
  // refer to the set of all nodes on a given processor.
  // Shell in that sense consists of multiple shells in the first sense).
  // The source is isotropic.

  Index_t useEPBoundary;
  Index_t useBoundaryFunction;
  Index_t boundaryFunctionInitDomain; // Initialize particle source function over entire domain

  Scalar_t boundaryFunctAmplitude; // Amplitude of source function in number/(cm2 ∗ s ∗ sr ∗ MeV /nucleon) at 1 AU for "Reference Species" (4He?). (TODO: At energy? (1MeV/nuc?) Scaled for other species, radii, energies?)
  Scalar_t boundaryFunctXi;        // Ratio of "Reference Species" (4He?) / H
  Scalar_t boundaryFunctGamma;     // Energy power law exponent (TODO: For reference species?)
  Scalar_t boundaryFunctBeta;      // Radial power law inverse exponent
  Scalar_t boundaryFunctEcutoff;   // Cutoff energy (MeV). (TODO: Treat the seed spectrum as flat below this energy?)


  // Shock Conditions:
  //
  // The shock solver will detect a shock and apply additional physics where detected.
  // (TODO: This needs to be documented; there's a paper to cite...)

  Index_t   shockSolver;          // Use the shock solver (If this is set to 1 then subTimeCouple needs to be 0)
  Scalar_t  shockDetectPercent;   // DlnN/Dlnr value above which it detects a shock
  Scalar_t  minInjectionEnergy;   // Minimum allowed injection energy (MeV)
  Scalar_t  shockInjectionFactor; // Multiplicative factor on the seed function for injection (TODO: relative to what?)


  // Ideal Cone CME:
  //
  // This will launch a CME into the simulation.

  Index_t   idealShock;            // Flag for using the ideal shock solution
  Scalar_t  idealShockSharpness;   // Shock width (higher is sharper by idealShockScaleLength). Basically idealShockScaleLength is divided by this number to make it easier to tweak the shock parameters between runs.
  Scalar_t  idealShockScaleLength; // Exponential scale length of shock variation (AU)
  Scalar_t  idealShockJump;        // Shock jump for speed, density and magnetic field (aka. Rankine-Hugoniot shock strength).
  Scalar_t  idealShockFalloff;
  Scalar_t  idealShockSpeed;       // Speed of the shock propagation (cm/s), separate from wind speed. In inertial frame not wind frame.
  Scalar_t  idealShockInitTime;    // Time for shock to arrive on inner domain in fractional days. The shock is launched such that the midpoint of the shock passes the inner boundary at this point in the simulation. (TODO: Affected by simStartTime?)
  Scalar_t  idealShockTheta;       // Location of center of cone CME (co-latitude, radian, pi/2 is on the equator)
  Scalar_t  idealShockPhi;         // Location of center of cone CME (azimuth, radian, 0.0 is centered on one face)
  Scalar_t  idealShockWidth;       // Width of cone CME (radian, entire domain (aka. isotropic) if 0.0)


  // Output Parameters:

  Index_t   unifiedOutput;       // Output all mhd and particle data for every node along streams. The name is historical; this is the main output that you almost always want.
  Index_t   pointObserverOutput; // (Unused)
  Index_t   streamFluxOutput;    // Output pre-computed flux instead of the particle distribution
  Index_t   epremDomain;         // Output position data for entire domain. Very often desirable, as this allows the node grid in inertial space.
  Index_t   unstructuredDomain;

  Scalar_t  unifiedOutputTime;
  Scalar_t  pointObserverOutputTime;
  Scalar_t  streamFluxOutputTime;
  Scalar_t  epremDomainOutputTime;
  Scalar_t  unstructuredDomainOutputTime; // (Unused)

  Index_t   FailModeDump; // (Unused) Dump out fail mode values
  Index_t   outputFloat;  // Output netcdf files in 32-bit precision (1) or 64-bit precision (0). Might be used to save disk space.

  int dumpFreq;        // Output cadence for all output and restart files (in number of steps)
  int outputRestart;   // (Unused)
  int dumpOnAbort;     // (Unused)
  int saveRestartFile; // (Unused)

  char * warningsFile; // File to dump warnings into


  // Other Parameters:

  Index_t   fluxLimiter;     // (Unused)
  Index_t   seedFunctionTest;


  // These params are initialized from the above inputs:

  Scalar_t   mhdUs;
  Scalar_t   mhdNsAu;
  Scalar_t   mhdBsAu;

  Scalar_t   simStartTimeDay;
  Scalar_t   simStopTimeDay;

} Config_t;

extern Config_t config;
extern config_t cfg;

void initGlobalParameters( char* configFilename );
void getParams( char* configFilename);
void setRuntimeConstants( void );

Index_t readInt(char *key, Index_t defaultVal, Index_t minVal, Index_t maxVal);
Scalar_t readDouble(char *key, Scalar_t defaultVal, Scalar_t minVal, Scalar_t maxVal);
const char *readString(char *key, char *defaultVal);
Scalar_t *readDoubleArray(char *key, int size, Scalar_t *defaultVal);

#endif
