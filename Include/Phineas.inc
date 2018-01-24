#ifndef(Phineas_Inc_Temp)
#declare Phineas_Inc_Temp = version;
#version 3.6


#macro Phineas(  left_arm_angle,
                left_elbow_angle,
                right_arm_angle,
                right_elbow_angle,
                left_leg_angle,
                left_knee_angle,
                right_leg_angle,
                right_knee_angle,
                head_angle
             )
    

#declare c_ph = <0,0,0>;        // left foot
#declare feet_center = c_ph + <0,9,0>;
#declare neck = feet_center + <0,9,0>;
#declare waist = feet_center + <0,5,0>;
#declare proportion = 1;    // Proporción

// LEFT ARM
#declare left_arm_begin = neck + <0.5,0,0>;
#declare left_shoulder_begin = <0,0,0>;
#declare left_shoulder_end = left_shoulder_begin + <0,1,0>;
#declare left_arm1_start = (left_shoulder_begin+left_shoulder_end)/2;
#declare left_arm1_size = <0,1,0>;
#declare left_arm1_end = left_arm1_start + left_arm1_size;
#declare left_arm2_start = left_arm1_end + <0,0,0>;
#declare left_arm2_size = <0,1.5,0>;
#declare left_arm2_end = left_arm2_start + <0,2,0>;

// RIGHT ARM
#declare right_arm_begin = neck + <-0.5,0,0>;
#declare right_shoulder_begin = <0,0,0>;
#declare right_shoulder_end = right_shoulder_begin + <0,1,0>;
#declare right_arm1_start = (right_shoulder_begin+right_shoulder_end)/2;
#declare right_arm1_size = <0,1,0>;
#declare right_arm1_end = right_arm1_start + right_arm1_size;
#declare right_arm2_start = right_arm1_end + <0,0,0>;
#declare right_arm2_size = <0,1.5,0>;
#declare right_arm2_end = right_arm2_start + <0,2,0>;

// LEFT LEG
#declare left_leg_begin = waist + <0.75,0,0>;
#declare left_leg1_begin = <0,0,0>;
#declare left_leg1_size = <0,2,0>;
#declare left_leg1_end = left_leg1_begin - left_leg1_size;
#declare left_leg2_begin = left_leg1_end;
#declare left_leg2_size = <0,1.5,0>;
#declare left_leg2_end = left_leg2_begin - left_leg2_size;
  

// RIGHT LEG
#declare right_leg_begin = waist + <-0.75,0,0>;
#declare right_leg1_begin = <0,0,0>;
#declare right_leg1_size = <0,2,0>;
#declare right_leg1_end = right_leg1_begin - right_leg1_size;
#declare right_leg2_begin = right_leg1_end;
#declare right_leg2_size = <0,1.5,0>;
#declare right_leg2_end = right_leg2_begin - right_leg2_size;
    



/********************************************** WHOLE CHARACTER ******************************************/
union{

    /************************************ HEAD ***********************************/
    union{
    
        // Back
        object{//Round_Cone2( point A, radius A, point B, radius B, rounding radius, merge on) 
                 Round_Cone2( <0,0,0>, 1    , <0,2,0>,  0.1, 1)  
                 
                 texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                            // normal { bumps 0.5 scale 0.05 }
                               finish { phong 1 reflection 0.00}
                          scale 0.25 
                        } // end of texture
                 scale<0.8,1,1>  rotate<60,0,0> translate <0,2.1,0>
               } // ----------------------------------------------------------- end Round_Cone
               
        // Nose       
        object{//Round_Cone2( point A, radius A, point B, radius B, rounding radius, merge on) 
                 Round_Cone2( <0,0,0>, 1    , <0,2,0>,  0.05, 1)  
                 
                 texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                            // normal { bumps 0.5 scale 0.05 }
                               finish { phong 1 reflection 0.00}
                          scale 0.25 
                        } // end of texture
                 scale<0.8,1,1>  rotate<-60,0,0> translate <0,2.1,0>
               } // ----------------------------------------------------------- end Round_Cone
        
        // Neck       
        object{//Round_Cone2( point A, radius A, point B, radius B, rounding radius, merge on) 
                 Round_Cone2( <0,0,0>, 0.95    , <0,2,0>,  0.1, 1)  
                 
                 texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                            // normal { bumps 0.5 scale 0.05 }
                               finish { phong 1 reflection 0.00}
                          scale 0.25 
                        } // end of texture
                 scale<0.8,1,1>  rotate<0,0,180> translate <0,2,0>
               } // ----------------------------------------------------------- end Round_Cone
               
               
        
        // Left eye
        sphere{
            <+0.5,3,0.2>
            0.5
            pigment { White }
        }
        
        sphere{
            <+0.6,3.2,-0.1>
            0.2
            pigment { Black }
        }   
          
          
             
        // Right eye       
        sphere{
            <-0.5,3,0.2>
            0.5
            pigment { White }
        }
        
        sphere{
            <-0.6,3.2,-0.1>
            0.2
            pigment { Black }
        }
        
        
          
          
        // Hair
        
        union{
        
            #for (i, 0, 5, 1) 
              sphere{ <0,0,0>, 0.3 
            
                    texture { pigment{color Red}
                              //pigment{color rgb< 1, 0.6, 0> }
                              //normal {bumps 0.5 scale 0.10}
                              finish { phong 1 phong_size 50}
                            } // end of texture
            
                    scale<5,1,1>  rotate<0,60*i,0>  translate <0,0,0>
                  } 
            #end // --------------- end of #for loop
            
            translate <0,2.1,0>
            scale <1,1,1>                            
            rotate<60,0,0>
            translate <0,2.1,0>   
        }
        
        rotate head_angle translate neck+<0,0,0>
            
    } // End of HEAD
    
    
    
    
           
    /******************************* BODY ***************************************/
    
    // Core
    object{//Round_Cone( point A, radius A, point B, radius B, rounding radius, merge on) 
             Round_Cone( <0,14,0>, 1.5    , <0,18.5,0>, 0.5 , 0.15, 0)  
             
             texture{ pigment{ gradient <0,1,0>
                                color_map{
                                    [ 0.0 color rgb<1,1,1> ]
                                    [ 0.5 color rgb<1,1,1> ]
                                    [ 0.5 color rgb<1,0.15,0> ]
                                    [ 1.0 color rgb<1,0.15,0> ]
                                   } // end color_map
                                 scale 6.4
                               } // end pigment
                     //normal  { bumps 0.5 scale  0.005 }
                       finish  { phong 1 reflection 0.00 }
                       scale 0.25
                     } // end of texture -------------------
             scale<1,1,1>  rotate<0,0,0> translate c_ph+<0,0.0,0>
          } // ----------------------------------------------------------- end Round_Cone 
    
                    
/*union{                    
    // Left Shoulder
    cone { <0,0,0>,0.4,<0,1,0>,0.2 
           //open
           texture{ pigment{ gradient <0,1,0>
                                color_map{
                                    [ 0.5 color rgb<1,0.15,0> ]
                                    [ 1.0 color rgb<1,0.15,0> ]
                                    [ 0.0 color rgb<1,1,1> ]
                                    [ 0.5 color rgb<1,1,1> ]
                                   } // end color_map
                                 scale 4
                               } // end pigment
                     //normal  { bumps 0.5 scale  0.005 }
                       finish  { phong 1 reflection 0.00 }
                       scale 0.25
                     } // end of texture -------------------
    
           scale <1,1,1> rotate<0,0,60> translate c_ph+<1.3,17.5,0>         
         } // end of cone -------------------------------------
         
          
    // Left Arm
    #declare Strength = 1; //(+ or -) strength of component's radiating density
    #declare Radius1  = 0.25; //(0 < Radius) outer sphere of influence on other components
    blob{
      threshold 0.01 // threshold (0.0 < threshold <= Strength) surface falloff threshold #
      cylinder { <0,0,0>,<0,1,0>, Radius1, Strength 
    
               texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                            // normal { bumps 0.5 scale 0.05 }
                               finish { phong 1 reflection 0.00}
                          scale 0.25 
                        } // end of texture
    
               scale <1,1,1> rotate<30,0,60> translate c_ph+<3,16.5,-0.5>
             } // end of cylinder -------------------------------------               
             
    cylinder { <0,0.9,0>,<0,3,0>, Radius1, Strength 
    
               texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                            // normal { bumps 0.5 scale 0.05 }
                               finish { phong 1 reflection 0.00}
                          scale 0.25 
                        } // end of texture
    
               scale <1,1,1> rotate<0,0,60> translate c_ph+<3,16.5,0>
             }
     } //------------------------------------------------------ end of blob object             
     
     rotate<0,0,0>
}    */
    
    
    // Complete left arm
    union{                    
        // Left Shoulder
        cone { <0,0,0>,0.2,<0,1,0>,0.4 
               //open
               texture{ pigment{ gradient <0,1,0>
                                    color_map{                                    
                                        [ 0.0 color rgb<1,1,1> ]
                                        [ 0.5 color rgb<1,1,1> ]
                                        [ 0.5 color rgb<1,0.15,0> ]
                                        [ 1.0 color rgb<1,0.15,0> ]
                                       } // end color_map
                                     scale 4
                                   } // end pigment
                         //normal  { bumps 0.5 scale  0.005 }
                           finish  { phong 1 reflection 0.00 }
                           scale 0.26
                         } // end of texture -------------------
        
               scale <1,1,1> rotate <0,0,0> translate left_shoulder_begin         
             } // end of cone -------------------------------------
             
              
        // Left Arm
        #declare Strength = 1; //(+ or -) strength of component's radiating density
        #declare Radius1  = 0.25; //(0 < Radius) outer sphere of influence on other components
        blob{
          threshold 0.01 // threshold (0.0 < threshold <= Strength) surface falloff threshold #
          cylinder { <0,0,0>,left_arm1_size, Radius1, Strength 
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
        
                   scale <1,1,1> rotate <0,0,0> translate left_arm1_start
                 } // end of cylinder -------------------------------------               
                 
          cylinder { <0,0,0>,left_arm2_size, Radius1, Strength 
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
        
                    
                   scale <1,1,1> rotate left_elbow_angle translate left_arm2_start
                 }
         } //------------------------------------------------------ end of blob object             
         
         rotate <0,0,-90>+left_arm_angle translate left_arm_begin
    }
    
    
    
/*    // Right Shoulder
    cone { <0,0,0>,0.4,<0,1,0>,0.2 
           //open
           texture{ pigment{ gradient <0,1,0>
                                color_map{
                                    [ 0.5 color rgb<1,0.15,0> ]
                                    [ 1.0 color rgb<1,0.15,0> ]
                                    [ 0.0 color rgb<1,1,1> ]
                                    [ 0.5 color rgb<1,1,1> ]
                                   } // end color_map
                                 scale 4
                               } // end pigment
                     //normal  { bumps 0.5 scale  0.005 }
                       finish  { phong 1 reflection 0.00 }
                       scale 0.25
                     } // end of texture -------------------
    
           scale <1,1,1> rotate<0,0,-60> translate c_ph+<-1.3,17.5,0>         
         } // end of cone -------------------------------------
         
         
         
             
    // Right Arm
    blob{
      threshold 0.01 // threshold (0.0 < threshold <= Strength) surface falloff threshold #
      cylinder { <0,0,0>,<0,1,0>, Radius1, Strength 
    
               texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                            // normal { bumps 0.5 scale 0.05 }
                               finish { phong 1 reflection 0.00}
                          scale 0.25 
                        } // end of texture
    
               scale <1,1,1> rotate<30,0,-60> translate c_ph+<-3,16.5,-0.5>
             } // end of cylinder -------------------------------------               
             
    cylinder { <0,0.9,0>,<0,3,0>, Radius1, Strength 
    
               texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                            // normal { bumps 0.5 scale 0.05 }
                               finish { phong 1 reflection 0.00}
                          scale 0.25 
                        } // end of texture
    
               scale <1,1,1> rotate<0,0,-60> translate c_ph+<-3,16.5,0>
             }
     } //------------------------------------------------------ end of blob object
*/



    // Complete right arm
    union{                    
        // Right Shoulder
        cone { <0,0,0>,0.2,<0,1,0>,0.4 
               //open
               texture{ pigment{ gradient <0,1,0>
                                    color_map{                                    
                                        [ 0.0 color rgb<1,1,1> ]
                                        [ 0.5 color rgb<1,1,1> ]
                                        [ 0.5 color rgb<1,0.15,0> ]
                                        [ 1.0 color rgb<1,0.15,0> ]
                                       } // end color_map
                                     scale 4
                                   } // end pigment
                         //normal  { bumps 0.5 scale  0.005 }
                           finish  { phong 1 reflection 0.00 }
                           scale 0.26
                         } // end of texture -------------------
        
               scale <1,1,1> rotate <0,0,0> translate right_shoulder_begin         
             } // end of cone -------------------------------------
             
              
        // Right Arm
        #declare Strength = 1; //(+ or -) strength of component's radiating density
        #declare Radius1  = 0.25; //(0 < Radius) outer sphere of influence on other components
        blob{
          threshold 0.01 // threshold (0.0 < threshold <= Strength) surface falloff threshold #
          cylinder { <0,0,0>,right_arm1_size, Radius1, Strength 
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
        
                   scale <1,1,1> rotate <0,0,0> translate right_arm1_start
                 } // end of cylinder -------------------------------------               
                 
          cylinder { <0,0,0>,right_arm2_size, Radius1, Strength 
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
        
                    
                   scale <1,1,1> rotate right_elbow_angle translate right_arm2_start
                 }
         } //------------------------------------------------------ end of blob object             
         
         rotate <0,0,0>+right_arm_angle translate right_arm_begin
    }             
             
     /*        
    // Left Hand
    #declare radius_finger=0.7;
    blob {
      threshold .15
      sphere{<0,0,0>, 3, 1 scale <1,1,0.5>}   //palm
      cylinder{<0,2,0>, <0,4 ,0>, radius_finger, 1 rotate <0,0,70>}      //lower ring
      cylinder{<0,2,0>, <0,5,0>,  radius_finger, 1 translate <1,0,0> rotate <0,0,-5>}     //lower middle
      cylinder{<0,2,0>, <0,5,0>,  radius_finger, 1 translate <0,0,0> rotate <0,0,0>}      //lower index
      cylinder{<0,2,0>, <0,5,0>,  radius_finger, 1 translate <-1,0,0> rotate <0,0,5>}  //lower thumb
      pigment{ color rgb< 1, 0.5, 0.5>*1.4  }
      
      scale <1,1,1> rotate<30,0,-60> translate c_ph+<-3,16.5,-0.5>
    }
    
    // Right Hand
    blob {
      threshold .15
      sphere{<0,0,0>, 3, 1 scale <1,1,0.5>}   //palm
      cylinder{<0,2,0>, <0,4 ,0>, radius_finger, 1 rotate <0,0,70>}      //lower ring
      cylinder{<0,2,0>, <0,5,0>,  radius_finger, 1 translate <1,0,0> rotate <0,0,-5>}     //lower middle
      cylinder{<0,2,0>, <0,5,0>,  radius_finger, 1 translate <0,0,0> rotate <0,0,0>}      //lower index
      cylinder{<0,2,0>, <0,5,0>,  radius_finger, 1 translate <-1,0,0> rotate <0,0,5>}  //lower thumb
      pigment{ color rgb< 1, 0.5, 0.5>*1.4  }
      
      scale <1,1,1>*0.15 rotate<0,0,60> translate c_ph+<-3,16.5,0>
    }
      */
    
    
    
    
    
    
    
    
    /****************************** LEGS *********************************************/
 
    // Trousers
    union{
        
        cone { <0,0,0>,0.75,<0,1.3,0>,0 
    
           texture { pigment{ color Blue}
                     finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture
    
           scale <1,1,1> rotate left_leg_angle translate left_leg_begin         
         } // end of cone -------------------------------------


        cylinder { <0,0,0>,<0,-1.5,0>, 0.75
           texture { pigment { color Blue }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture
    
           scale <1,1,1> rotate left_leg_angle  translate left_leg_begin
        } // end of cylinder -------------------------------------
        
        
        cone { <0,0,0>,0.75,<0,1.3,0>,0 
    
           texture { pigment{ color Blue}
                     finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture
    
           scale <1,1,1> rotate right_leg_angle translate right_leg_begin         
         } // end of cone -------------------------------------
        
        cylinder { <0,0,0>,<0,-1.5,0>, 0.75 
               texture { pigment { color Blue }
                       //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                         finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture
        
               scale <1,1,1> rotate right_leg_angle translate right_leg_begin
        } // end of cylinder -------------------------------------
        
        
        
        translate <0,0,0>
    } //End of Trousers union
    
    
    
    // Left Leg
    union{
        blob{
          threshold 0.01 // threshold (0.0 < threshold <= Strength) surface falloff threshold #
          cylinder { <0,0,0>,-left_leg1_size, 0.4, 1
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
                    scale <1,1,1> rotate <0,0,0> translate left_leg1_begin
                 } // end of cylinder -------------------------------------               
                 
          cylinder { <0,0,0>,-left_leg2_size, 0.4, 1 
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
                    scale <1,1,1> rotate left_knee_angle translate left_leg2_begin
                 }                 
                        
        } //------------------------------------------------------ end of blob object
        
        // Left Shoe
        union{ 
            cylinder { <0,0.8,0>,<0,1,0>, 0.50 
                
                           texture { pigment { color rgb<1,1,1> }
                                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                   } // end of texture
                
                           scale <1,1,2> rotate<0,0,0> translate<0,0,0>
                         } // end of cylinder -------------------------------------   
            
            difference{
            
                
                            
                             
                 sphere { <0,1,0>, 0.5 
                
                        texture { pigment{ gradient <0,0,1>
                                    color_map{
                                        [ 0.0 color Blue ]
                                        [ 0.5 color Blue ]
                                        [ 0.5 color White ]
                                        [ 1.0 color White ]
                                       } // end color_map
                                     scale 0.5
                                   } // end pigment
                                  finish { phong 1.0 reflection 0.00}
                                } // end of texture
                
                          scale<1,1,2>  rotate<0,0,0>  translate<0,0,0>  
                       }  // end of sphere ----------------------------------- 
            
             
             cylinder { <0,0.0,0>,<0,0.8,0>, 0.50 
                
                           texture { pigment { color rgb<1,1,1> }
                                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                   } // end of texture
                
                           scale <1,1,2> rotate<0,0,0> translate<0,0,0>
                         } // end of cylinder -------------------------------------            
            } 
            
            translate left_leg2_end-<0,1.2,0.5>
        } // End of SHOE union
                         
        rotate left_leg_angle translate left_leg_begin   
    } // End of LEFT LEG union             
       
         

    
    // Right Leg
    union{
        blob{
          threshold 0.01 // threshold (0.0 < threshold <= Strength) surface falloff threshold #
          cylinder { <0,0,0>,-right_leg1_size, 0.4, 1
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
                    scale <1,1,1> rotate <0,0,0> translate right_leg1_begin
                 } // end of cylinder -------------------------------------               
                 
          cylinder { <0,0,0>,-right_leg2_size, 0.4, 1 
        
                   texture{ pigment{ color rgb< 1, 0.5, 0.5>*1.4  } // very light red  
                                // normal { bumps 0.5 scale 0.05 }
                                   finish { phong 1 reflection 0.00}
                              scale 0.25 
                            } // end of texture
                    scale <1,1,1> rotate right_knee_angle translate right_leg2_begin
                 }                 
                        
        } //------------------------------------------------------ end of blob object
        
        // Right Shoe
        union{ 
            cylinder { <0,0.8,0>,<0,1,0>, 0.50 
                
                           texture { pigment { color rgb<1,1,1> }
                                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                   } // end of texture
                
                           scale <1,1,2> rotate<0,0,0> translate<0,0,0>
                         } // end of cylinder -------------------------------------   
            
            difference{
            
                
                            
                             
                 sphere { <0,1,0>, 0.5 
                
                        texture { pigment{ gradient <0,0,1>
                                    color_map{
                                        [ 0.0 color Blue ]
                                        [ 0.5 color Blue ]
                                        [ 0.5 color White ]
                                        [ 1.0 color White ]
                                       } // end color_map
                                     scale 0.5
                                   } // end pigment
                                  finish { phong 1.0 reflection 0.00}
                                } // end of texture
                
                          scale<1,1,2>  rotate<0,0,0>  translate<0,0,0>  
                       }  // end of sphere ----------------------------------- 
            
             
             cylinder { <0,0.0,0>,<0,0.8,0>, 0.50 
                
                           texture { pigment { color rgb<1,1,1> }
                                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                   } // end of texture
                
                           scale <1,1,2> rotate<0,0,0> translate<0,0,0>
                         } // end of cylinder -------------------------------------            
            } 
            
            translate right_leg2_end-<0,1.2,0.5>
        } // End of SHOE union
                         
        rotate right_leg_angle translate right_leg_begin   
    } // End of RIGHT LEG union



} //End of WHOLE CHARACTER union


#end

#version Phineas_Inc_Temp

#end