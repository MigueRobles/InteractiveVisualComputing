#ifndef( Perry_Inc_Temp)
#declare Perry_Inc_Temp = version;
#version 3.6 

#declare w = 3.7; //width
#declare h = 1; //height 
#declare d = -2; //depth
#declare proportion = 1.4;  

#declare c_f = <0,8.5,0>;
#declare c =   <0,0,0>;
  

#macro Perry(right_arm_angle, left_arm_angle,right_leg_angle,left_leg_angle )

//PERRY------------------------------------------------------------------------------------------------------------------------------------------------
union{
    //Body
    
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(<0,0,0>,<w,h,d>, 0.25   , 0)  
             
            texture{ pigment{ color Cyan}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate c
          } // --------------------------------------------------------- 
    //******
    union{
        //ArmR   
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.2,-0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate  c
              } // ---------------------------------------------------------
              
        //HandR      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.5,-0.2,0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate c+<0,-1.5,-0.85>
              } // ---------------------------------------------------------
             scale<1,1,1>  rotate right_arm_angle translate c+<1.2,0.2,-0.2>
          }
    //*****
      union{
        //ArmL   
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.2,-0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate  c
              } // ---------------------------------------------------------
              
        //HandL      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.5,-0.2,0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate c+<0,-1.5,-0.85>
              } // ---------------------------------------------------------
             scale<1,1,1>  rotate left_arm_angle translate c+<1.2,0.2,-1.8>
          }
    //*****
      union{
         //LegR   
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.2,-0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate  c
              } // ---------------------------------------------------------
              
        //FootR      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.5,-0.2,0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate c+<0,-1.5,-0.85>
              } // ---------------------------------------------------------
             scale<1,1,1>  rotate right_leg_angle translate c+<4.5,0.2,-0.2>  
             
             }
    //*****
      union{
         //LegL   
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.2,-0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate  c
              } // ---------------------------------------------------------
              
        //FootL      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.5,-0.2,0.6>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
                scale<1,1,1>*proportion  rotate<0, 0,0> translate c+<0,-1.5,-0.85>
              } // ---------------------------------------------------------
             scale<1,1,1>  rotate left_leg_angle translate c+<4.5,0.2,-1.8>  
             
             }
    
    //Left eye
    
    sphere { <0,0,0>, 0.3 
    
            texture { pigment{ color White}
                      finish { phong 1.0 reflection 0.00}
                    } // end of texture
    
              scale<1,1,1>*proportion  rotate<0,0,0>  translate c+<0.2,0.5,-1.6>*proportion  
           }  // end of sphere -----------------------------------
           //Iris1
                sphere { <0,0,0>, 0.1 
                
                        texture { pigment{ color Black}
                                  finish { phong 1.0 reflection 0.00}
                                } // end of texture
                
                          scale<1,1,1>*proportion  rotate<0,0,0>  translate c+<-0.05,0.5,-1.65>*proportion  
                       }  // end of sphere -----------------------------------  
                       
                       
                       
                       
                       
    //Rigth eye       
    sphere { <0,0,0>, 0.3 
    
            texture { pigment{ color White}
                      finish { phong 1.0 reflection 0.00}
                    } // end of texture
    
              scale<1,1,1>*proportion  rotate<0,0,0>  translate c+<0.2,0.5,-0.4>*proportion  
           }  // end of sphere ----------------------------------- 
    
                       
            //Iris2       
            sphere { <0,0,0>, 0.1 
            
                    texture { pigment{ color  Black}
                              finish { phong 1.0 reflection 0.00}
                            } // end of texture
            
                     scale<1,1,1>*proportion  rotate<0,0,0>  translate c+<-0.05,0.5,-0.3>*proportion  
                   }  // end of sphere ----------------------------------- 
           
           
    // Pico
    
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(<0,0,0>,<0.8,-0.1,-0.8>, 0.1   , 0)  
             
            texture{ pigment{ color Orange}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate c+<-0.8,0.3,-0.85>
          } // ---------------------------------------------------------
    
    //Nose            
    triangle { 
                    c+<-0.01, 0, -0.75>, c+<-0.01, 0, -1.25>, c+<-0.01, 0.5, -1>
                    texture { pigment{ color Orange } 
                    finish { phong 1.0 }
                  }
                  scale<1,1,1>*proportion
                   }
                   
                   
    //Cola 
    
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box( <0,0,0>, <-1.3,h-0.8,-0.9>, 0.1   , 0)  
             
            texture{ pigment{ color Red}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate c+<2*w-0.5,0.1,-0.8>
          } // ---------------------------------------------------------        
}
#end
//------------------------------------- end of macro
#version  Perry_Inc_Temp;
#end
//------------------------------------- end of include file