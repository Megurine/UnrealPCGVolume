1) Rename <b>APKM_PCGVolume</b> by another Name in the file (and the filenames) if you want.
2) Rename <b>POKEMONGAME_API</b> by your own project _API in .h line 24.
3) Add <b>"UnrealEd"</b> in the <i>PublicDependencyModuleNames</i> of your <i>Build.cs</i>.
4) Use the <b>APKM_PCGVolume</b> instead of <b>APCGVolume</b> in your scenes, there is a variable <i>DisablePCGMode</i> who disable PCGGeneration during other editmodes :
<p align="center">
  <img src="https://ahri.fr/images/Screenshot_346.png">
</p>
<ul>
  <li>Disable on Landscape mode (<b>by default</b>) (to avoid OutOfMemory leak crash with a lot of instances during landscape editing)</li>
  <li>Disable on every modes</li>
  <li>Dont disable</li>
</ul>




  
