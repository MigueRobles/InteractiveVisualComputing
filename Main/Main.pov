#include "colors.inc"
#include "shapes.inc" 
    
#declare w = 4; //width
#declare h = 1; //height 
#declare d = -2; //depth
#declare proportion_p = 1.4;
#declare proportion = 1.2;
#declare proportion_f = 1.2;
#declare proportion_h = 10;  
  


#declare c_f = <0,8.5,-5>;
#declare c_ph = <-3,-6,5>;
#declare c =   <0,1,-2>;
        
camera{

    location <100,20,-8>
    look_at <50,6,-8>
    rotate<0,0,0> 
    translate<0,0,0>

} 



// sun ---------------------------------------------------------------------
light_source{<-1500,2000,2500> color White}

// sky -------------------------------------------------------------- 
plane{<0,1,0>,1 hollow  
       texture{ pigment{ bozo turbulence 0.92
                         color_map { [0.00 rgb <0.20, 0.20, 1.0>*0.9]
                                     [0.50 rgb <0.20, 0.20, 1.0>*0.9]
                                     [0.70 rgb <1,1,1>]
                                     [0.85 rgb <0.25,0.25,0.25>]
                                     [1.0 rgb <0.5,0.5,0.5>]}
                        scale<1,1,1.5>*2.5  translate< 0,clock,0>
                       }
                finish {ambient 1 diffuse 0} }      
       scale 10000}           /*
// fog on the ground -------------------------------------------------
fog { fog_type   2
      distance   50
      color      White  
      fog_offset 0.1
      fog_alt    1.5
      turbulence 1.8
    }
               */
// ground ------------------------------------------------------------
plane { <0,1,0>, 0 
        texture{ pigment{ color rgb<0.35,0.65,0.0>*0.72 }
	         normal { bumps 0.75 scale 0.015 }
                 finish { phong 0.1 }
               } // end of texture
      } // end of plane
 //--------------------------------------------------------------------------------------------------------------------------------------------Perry****
                     
#ifndef( Perry_Inc_Temp)
#include "..\Include\Perry.inc"                                             
#end

#declare right_arm_angle = <0,0,30*sin(pi*clock*2)>; 
#declare left_arm_angle = <0,0,-30*sin(pi*clock*2)>;
#declare right_leg_angle = <0,0,-30*sin(pi*clock*2)>;
#declare left_leg_angle = <0,0,30*sin(pi*clock*2)>;


object{ Perry(right_arm_angle,left_arm_angle,right_leg_angle,left_leg_angle)
        scale <1,1,1>
        rotate<0,180,0> 
        translate<45,1.7,-9>
    }
    
 //--------------------------------------------------------------------------------------------------------------------------------------------AgentPi****
                                             /*
#ifndef( AgentPi_Inc_Temp)
#include "..\Include\AgentPi.inc"                                             
#end

#declare right_arm_angle = <-45,0,30*sin(pi*clock*2)>; 
#declare left_arm_angle = <45,0,-30*sin(pi*clock*2)>;
#declare right_leg_angle = <0,0,-30*sin(pi*clock*2)>;
#declare left_leg_angle = <0,0,30*sin(pi*clock*2)>;


object{ AgentPi(right_arm_angle,left_arm_angle,right_leg_angle,left_leg_angle)
        scale <1,1,1>*1.2
        rotate<0,0,0> 
        translate<50-clock*5,0.5,-25>
    }                                 */
//------------------------------------------------------------------------------------------------------------------------------------------------Phineas****
#ifndef( Phineas_Inc_Temp)
#include "..\Include\Phineas.inc"                                             
#end

#declare left_arm_angle = <-30*sin(pi*clock),0,-45>;  
#declare left_elbow_angle = <-30*sin(pi*clock),0,0>;  
#declare right_arm_angle = <30*sin(pi*clock),0,135>;  
#declare right_elbow_angle = <30*sin(pi*clock),0,0>;  
#declare left_leg_angle = <30*sin(pi*clock),0,0>;  
#declare left_knee_angle = <30*sin(pi*clock),0,0>;  
#declare right_leg_angle = <-30*sin(pi*clock),0,0>;  
#declare right_knee_angle = <-30*sin(pi*clock),0,0>;  
#declare head_angle = <-15-10*sin(pi*clock/2),0,0>;  
 
object{ Phineas(left_arm_angle,left_elbow_angle,right_arm_angle,right_elbow_angle, left_leg_angle, left_knee_angle, right_leg_angle, right_knee_angle, head_angle)
        scale <1,1,1>
        rotate<0,140,0> 
        translate<50,-10,-15>
    }


//------------------------------------------------------------------------------------------------------------------------------------------------FERB**** 

#ifndef( Ferb_Inc_Temp)
#include "..\Include\Ferb.inc"                                             
#end

#declare left_arm_angle = <-30*sin(pi*clock),0,-45>;  
#declare left_elbow_angle = <-30*sin(pi*clock),0,0>;  
#declare right_arm_angle = <30*sin(pi*clock),0,45>;  
#declare right_elbow_angle = <30*sin(pi*clock),0,0>;  
#declare left_leg_angle = <30*sin(pi*clock),0,0>;  
#declare left_knee_angle = <30*sin(pi*clock),0,0>;  
#declare right_leg_angle = <-30*sin(pi*clock),0,0>;  
#declare right_knee_angle = <-30*sin(pi*clock),0,0>;  
#declare head_angle = <-15-10*sin(pi*clock/2),0,0>;  
 
object{ Ferb(left_arm_angle,left_elbow_angle,right_arm_angle,right_elbow_angle, left_leg_angle, right_leg_angle)
        scale <1,1,1>
        rotate<0,40,0> 
        translate<50,8.7,2>
    }

                                                                                                /*
//------------------------------------------------------------------------------------------------------------------------------------------------Houses****   


//----------------------------------------------------------------------------- textures
#declare Wall_Texture_Outside = 
      texture { pigment{ color Orange*2}
                normal { bumps 0.5 scale 0.005} 
                finish { phong 1}
              } // end of texture
//--------------------------------------------------------
#declare Wall_Texture_Inside = 
      texture { pigment{ color Cyan*1.1}
                finish { phong 1}
              } // end of texture
//--------------------------------------------------------
#declare Roof_Texture = 
// layered texture!!!
      texture { pigment{ color Scarlet*1.3}
                normal { gradient z scallop_wave scale<1,1,0.15>} 
                finish { phong 1}
              } // end of texture
 
      texture { pigment{ gradient x 
                         color_map{[0.00 color Clear]
                                   [0.90 color Clear]
                                   [0.95 color White*0.1]
                                   [1.00 color White*0.1]}
                          scale 0.25}
                 finish { phong 1}
              } // end of texture

//--------------------------------------------------------
#declare Window_Texture = 
         texture{ pigment{ color rgb< 0.75, 0.5, 0.30>*0.35 } // brown  
                  // pigment{ color White*1.2}
                  finish { phong 0.1}}
//--------------------------------------------------------------------------------------- 
//---------------------------------------------------------------------------------------
#include "..\Include\House_1_0.inc" 
//-------------------------------------------------------------------------------------// 
#for (j, -80, 80,10)   
    #for (i, -80, 80, 8) 
        #if ( i = 0 & j = 0 )
        
        #else      
             object{ House_1_0(  2.50, // Half_House_Width_X, // >= 2.00
                        5.50, // Total_House_Width_Z,// >= 2.00
                        5.10, // House_Height_Y,     // >= 2.00
                        45,   // Roof___Angle, // ca. 10 ~ 60 degrees
                          
                        Wall_Texture_Outside
                        Wall_Texture_Inside 
                        Window_Texture                                                    
                        Roof_Texture
                       ) //----------------------------------------------------------------//
                    scale <1,1,1>*proportion_h   rotate<0,0,0>   translate<12*j,0,15*i>
                    } 
         #end
    #end // --------------- end of #for loop
#end // --------------- end of #for loop   

                                                                                                   */
                                           
//---------------------------------------------------------------------------------------------------------------------------------------------------Tree****
union{
    sphere { <0,0,0>, 1.00 
             texture { pigment{ color rgb<0.35,0.65,0.0>*0.9} //color rgb<0.2,0.7,0.05> }                                     
                       normal { bumps 1.75 scale 0.05} 
                       finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                     } // end of texture
              scale<1,1,1>*10  rotate<0,0,0>  translate<0,25,-50>  
           }  // end of sphere ------------------------------
           
           
    object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(<0,0,0>, <0,2,0>, 0.25 ,       0.20,   0)  
             
             texture{ pigment{ Brown }
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>*10  rotate<0, 0,0> translate<0,-2,-50>
           } // ---------------------------------------------------------
           
      scale<1,1,1>  rotate<0, 0,0> translate<-12,0,0>   
}

union{
    sphere { <0,0,0>, 1.00 
             texture { pigment{ color rgb<0.35,0.65,0.0>*0.9} //color rgb<0.2,0.7,0.05> }                                     
                       normal { bumps 1.75 scale 0.05} 
                       finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                     } // end of texture
              scale<1,1,1>*10  rotate<0,0,0>  translate<0,25,-50>  
           }  // end of sphere ------------------------------
           
           
    object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(<0,0,0>, <0,2,0>, 0.25 ,       0.20,   0)  
             
             texture{ pigment{ Brown }
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>*10  rotate<0, 0,0> translate<0,-2,-50>
           } // ---------------------------------------------------------
           
      scale<1,1,1>  rotate<0, 0,0> translate<85,0,0>   
}

union{
    sphere { <0,0,0>, 1.00 
             texture { pigment{ color rgb<0.35,0.65,0.0>*0.9} //color rgb<0.2,0.7,0.05> }                                     
                       normal { bumps 1.75 scale 0.05} 
                       finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                     } // end of texture
              scale<1,1,1>*10  rotate<0,0,0>  translate<0,25,-50>  
           }  // end of sphere ------------------------------
           
           
    object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(<0,0,0>, <0,2,0>, 0.25 ,       0.20,   0)  
             
             texture{ pigment{ Brown }
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>*10  rotate<0, 0,0> translate<0,-2,-50>
           } // ---------------------------------------------------------
           
      scale<1,1,1>  rotate<0, 0,0> translate<-12,0,100>   
}
           /*
//--------------------------------------------------------------------------------------------------------------------------------------------------Cage****     
                                                                                                                                    

#ifndef( Cage_Inc_Temp)
#include "..\Include\Cage.inc"                                             
#end

 
object{ Cage()
        scale <1,1,1>
        rotate<0,90,0> 
        translate<45-clock*5,0,6>
    }
    
                */
                      