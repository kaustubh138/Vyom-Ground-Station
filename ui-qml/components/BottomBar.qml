import QtQuick 2.15
import QtQuick 2.0

Rectangle {
     id: bottomBar
     anchors {
         left: parent.left
         right: parent.right
         bottom: parent.bottom
     }
     color: "#222B45"
     height: parent.height / 18

         
             
       Rectangle{
         id:outerCircle1
         color:"transparent"
         border.width:1.5
         border.color:"white"
         radius:100
         height:20
         width:20
          anchors{
              left:bottomBar.left
              top:bottomBar.top
              topMargin:5
              leftMargin:20
                  }      
                  
                  property bool checked:false
                    
                  Rectangle{
                       height:outerCircle1.height*0.6
                       visible:outerCircle1.checked
                       width:height
                       color:"green"
                       radius:outerCircle1.radius         
                       anchors.centerIn:parent 
                           }

                  MouseArea{
                      anchors.fill:parent
                      hoverEnabled:true
                      onClicked:outerCircle1.checked=!outerCircle1.checked
                  }
       }
          
                      Text{
                            id:mechSys
                            anchors {
                               left:bottomBar.left
                               top: bottomBar.top
                               leftMargin:47
                               topMargin:5
                                      }
                            color:"#C5B2B2"
                            text: qsTr("Mechanical Gyro Control System")
                            font.pixelSize: 14
                                      }


                      
       Rectangle{
         id:outerCircle2
         color:"transparent"
         border.width:1.5
         border.color:"white"
         radius:100
         height:20
         width:20
          anchors{
              left:bottomBar.left
              top:bottomBar.top
              topMargin:5
              leftMargin:300
                  }      
                  
                  property bool checked:false
                    
                  Rectangle{
                       height:outerCircle2.height*0.6
                       visible:outerCircle2.checked
                       width:height
                       color:"green"
                       radius:outerCircle2.radius         
                       anchors.centerIn:parent 
                           }

                  MouseArea{
                      anchors.fill:parent
                      hoverEnabled:true
                      onClicked:outerCircle2.checked=!outerCircle2.checked
                  }
       }
          
                      Text{
                            id:autoPara
                            anchors {
                               left:bottomBar.left
                               top: bottomBar.top
                               leftMargin:325
                               topMargin:5
                                      }
                            color:"#C5B2B2"
                            text: qsTr("Auto Paragliding System")
                            font.pixelSize: 14
                                      }



                                            

                    Rectangle{
                              id:outerCircle3
                              color:"transparent"
                              border.width:1.5
                              border.color:"white"
                              radius:100
                              height:20
                              width:20
                              anchors{
                                     left:bottomBar.left
                                     top:bottomBar.top
                                     topMargin:5
                                     leftMargin:550
                                      }      
                  
                  property bool checked:false
                    
                  Rectangle{
                       height:outerCircle3.height*0.6
                       visible:outerCircle3.checked
                       width:height
                       color:"green"
                       radius:outerCircle3.radius         
                       anchors.centerIn:parent 
                           }

                  MouseArea{
                      anchors.fill:parent
                      hoverEnabled:true
                      onClicked:outerCircle3.checked=!outerCircle3.checked
                  }
       }
          
                      Text{
                            id:cam
                            anchors {
                               left:bottomBar.left
                               top: bottomBar.top
                               leftMargin:575
                               topMargin:5
                                      }
                            color:"#C5B2B2"
                            text: qsTr("Camera")
                            font.pixelSize: 14
                                      }



















}
