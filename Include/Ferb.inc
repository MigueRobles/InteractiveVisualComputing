#ifndef(Ferb_Inc_Temp)
#declare Ferb_Inc_Temp=version;
#version 3.6

#macro Ferb(left_elbow_angle, left_arm_angle, right_elbow_angle, right_arm_angle, left_leg_angle, right_leg_angle) 

    //Physiognomy
    #declare head_size = 6;
    #declare body_size = 5.5;
    
    //Face factions positions variables
    #declare face_up_position = c+<0,head_size,0>;
    #declare face_down_position = c;
    #declare radius_up_face = 1.3;
    #declare radius_down_face = 0.8;
    #declare right_eye_position = c+<0.6,4,-0.9>;
    #declare left_eye_position = c+<-0.4,4,-0.9>;
    #declare eye_radius = 0.75;
    #declare nose_position_corner1 = left_eye_position+<-0.3,-2,-1>;
    #declare nose_position_corner2 = right_eye_position+<0.1,-0.75,0>;
    #declare base_hair_position = face_up_position+<0,0.1,0>;
    
    //Body position variables
    #declare body_up_position = face_down_position;
    #declare body_down_position = body_up_position+<0,-body_size,0>;
    #declare arm_size = 4;                                                 
    #declare arm_radius = 0.3;
    #declare arm_left_up_position = body_up_position+<-0.5, -0.3, 0>;
    #declare arm_left_down_position = arm_left_up_position+<-arm_size,0,0>;
    #declare arm_right_up_position = body_up_position+<0.5,-0.3,0>;
    #declare leg_size = 3;
    #declare leg_radius = 0.3;
    #declare arm_inclination = 1.2;
    #declare arm_right_elbow_position = arm_right_up_position+<1.5,-arm_inclination,0>;
    #declare arm_right_down_position = arm_right_up_position+<arm_size,0,0>;
    #declare leg_left_up_position = body_down_position+<-0.5,0,0>;
    #declare arm_left_elbow_position = arm_left_up_position+<-1.5,-arm_inclination,0>;
    #declare leg_left_down_position = leg_left_up_position+<0,-leg_size,0>;
    #declare leg_right_up_position = body_down_position+<0.5,0,0>;
    #declare leg_right_down_position = leg_right_up_position+<0,-leg_size,0>;
    
    //Color variables
    #declare skin_color = color rgb< 1, 0.5, 0.5>*1.4;
     
    union{       
    
        //Ferb's head base
        cone{
            face_up_position,radius_up_face
            face_down_position, radius_down_face
            texture{
                pigment{color rgb< 1, 0.5, 0.5>*1.4}
            }
        }
      
        union{
        
            //Right eye
            sphere{
                right_eye_position
                eye_radius-0.2
                pigment {White}
            }
            
            sphere{
                right_eye_position+<0,0,-0.6>
                eye_radius-0.6
                pigment{Black}
            }
        
        }
        //Left eye
        union{
            
            sphere{
                left_eye_position
                eye_radius
                pigment{White}
            
            }
            
            sphere{
                left_eye_position+<0,0,-0.8>
                eye_radius-0.6
                pigment{Black}
            } 
        }
        
        //Nose
        object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(nose_position_corner1,nose_position_corner2, 0.25   , 0)  
             
            texture{ pigment{ skin_color}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }
                    }
            scale<1,1,1>  rotate<0, 0,0> translate<0,0.1,0>
        } // ---------------------------------------------------------
        union{            
            cylinder{
                body_up_position,
                body_down_position,
                radius_down_face+0.1
                texture{
                    pigment{White}
                }
            }
            object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(body_up_position+<0,-0.8,0>, body_down_position, radius_down_face+0.20 ,       0.20,   0)  
             texture{ pigment{DarkPurple}
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>  rotate<0, 0,0> translate<0,0.00,0>
           } // ---------------------------------------------------------
            
        }
       
        //Hair
        union{
        
            cylinder{
                face_up_position,
                base_hair_position,
                radius_up_face
                pigment{color Green}
            }
            cone{
                base_hair_position,
                0.5,
                base_hair_position+<0,0.4,-8>
                0
                texture{
                    pigment{Green}
                }
                
            }
            cone{
                base_hair_position+<-0.9,0,0>,
                0.5,
                base_hair_position+<0,0.2,-8>
                0
                texture{
                    pigment{Green}
                }
                rotate<-3,0,0>
            }
            cone{
                base_hair_position+<0.2,0,0>
                0.8,
                base_hair_position+<1.2,0.5,-5>
                0
                texture{
                    pigment{Green}
                }
            }
            cone{
                base_hair_position+<-0.3,0,0>
                0.8
                base_hair_position+<-1,0.3,-3>,
                0
                texture{
                    pigment{Green}
                }
            }
            cone{
                base_hair_position+<0.3,0,-0.3>
                0.8
                base_hair_position+<0.3,0.5,-1.2>
                0
                texture{
                    pigment{Green}
                }
            }
            
        }
        union{
            //Left arm
            blob {
                threshold 0.1
                cylinder{<0,0,0>, arm_left_elbow_position+<0,-0.6,0> - arm_left_up_position, arm_radius, 2}    //lower pinky
                cylinder{<0,0,0>, <0.0,-0.7,-1>, arm_radius, 2 rotate left_elbow_angle translate arm_left_elbow_position+<0,-0.6,0> - arm_left_up_position}  //upper pinky
                texture{
                    pigment{ skin_color }
                }
            }
            cylinder{
                <0,0,0>,
                arm_left_down_position+<3,-arm_inclination,0>-arm_left_up_position
                arm_radius+0.1
                texture{
                    pigment{White}
                }
            }
            rotate left_arm_angle translate arm_left_up_position 
        }
        union{
            //Right arm
            blob {
                threshold 0.1
                cylinder{<0,0,0>, arm_right_elbow_position+<0,-0.6,0> - arm_right_up_position, arm_radius, 2}    //lower pinky
                cylinder{<0,0,0>, <0.0,-0.7,-1>, arm_radius, 2 rotate right_elbow_angle translate arm_right_elbow_position+<0,-0.6,0> - arm_right_up_position}  //upper pinky
                texture{
                    pigment{ skin_color }
                }
            }
            cylinder{
                <0,0,0>,
                arm_right_down_position+<-3,-arm_inclination,0>-arm_right_up_position
                arm_radius+0.1
                texture{
                    pigment{White}
                }
            }
            rotate right_arm_angle translate arm_right_up_position 
        }
        union{
            //Right leg
            object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(<0,0,0>, leg_right_down_position-leg_right_up_position, leg_radius ,       0.20,   0)  
             
             texture{ pigment{skin_color}
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>  rotate<0, 0,0> translate<0,0.00,0>
           } // ---------------------------------------------------------
           
           //Right leg
            object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(<0,0,0>, leg_left_down_position+<0,1,0>-leg_left_up_position, leg_radius+0.1, 0.20,   0)  
             
             texture{ pigment{DarkPurple}
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>  rotate<0, 0,0> translate<0,0.00,0>
           }
            
            //Left shoe
            union{
            
                cylinder { <0,0,0>, <0,0.2,0>, 0.50 
                    
                               texture { pigment { color rgb<1,1,1> }
                                       //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                         finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                       } // end of texture
                    
                               scale <2,1,1> rotate<0,0,0> translate<0,0,0>
                             } // end of cylinder -------------------------------------   
                
                difference{
                
                    
                                
                                 
                     sphere { <0,0.2,0>, 0.5 
                    
                            texture { pigment{ Black}
                                      finish { phong 1.0 reflection 0.00}
                                    } // end of texture
                    
                              scale<2,1,1>  rotate<0,0,0>  translate<0,0,0>  
                           }  // end of sphere ----------------------------------- 
                
                 
                 cylinder {<0,-0.8,0>, <0,0,0>, 0.50 
                    
                               texture { pigment { color rgb<1,1,1> }
                                       //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                         finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                       } // end of texture
                    
                               scale <2,1,1> rotate<0,0,0> translate<0,0,0>
                             } // end of cylinder -------------------------------------            
                }     
                rotate<0,90,0>
                translate<0,0,-0.35>+(leg_left_down_position - leg_left_up_position) 
            }
            rotate left_leg_angle translate leg_left_up_position
        }
        union{
            //Right leg
            object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(<0,0,0>, leg_right_down_position-leg_right_up_position, leg_radius ,       0.20,   0)  
             
             texture{ pigment{skin_color}
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>  rotate<0, 0,0> translate<0,0.00,0>
           } // ---------------------------------------------------------
           
           //Right leg
            object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
             Round_Cylinder(<0,0,0>, leg_right_down_position+<0,1,0>-leg_right_up_position, leg_radius+0.1, 0.20,   0)  
             
             texture{ pigment{DarkPurple}
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                      finish { phong 1 }
                    }
             scale<1,1,1>  rotate<0, 0,0> translate<0,0.00,0>
           }
            
            //Right shoe
            union{
            
                cylinder { <0,0,0>, <0,0.2,0>, 0.50 
                    
                               texture { pigment { color rgb<1,1,1> }
                                       //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                         finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                       } // end of texture
                    
                               scale <2,1,1> rotate<0,0,0> translate<0,0,0>
                             } // end of cylinder -------------------------------------   
                
                difference{
                
                    
                                
                                 
                     sphere { <0,0.2,0>, 0.5 
                    
                            texture { pigment{ Black}
                                      finish { phong 1.0 reflection 0.00}
                                    } // end of texture
                    
                              scale<2,1,1>  rotate<0,0,0>  translate<0,0,0>  
                           }  // end of sphere ----------------------------------- 
                
                 
                 cylinder {<0,-0.8,0>, <0,0,0>, 0.50 
                    
                               texture { pigment { color rgb<1,1,1> }
                                       //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                                         finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                                       } // end of texture
                    
                               scale <2,1,1> rotate<0,0,0> translate<0,0,0>
                             } // end of cylinder -------------------------------------            
                }     
                rotate<0,90,0>
                translate<0,0,-0.35>+(leg_right_down_position - leg_right_up_position) 
            }
            rotate right_leg_angle translate leg_right_up_position
        }
    }

#end

#version Ferb_Inc_Temp
#end
