import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.15
import QtQuick.Extras.Private 1.0
import QtQuick.Shapes 1.15

Window {
    id:mainWaindow
    width: 1900
    height: 1010
    visible: true
    visibility: "Maximized"
    color: "#161a1d"
    title: qsTr("ASU Racing Team")



    /***************************************************************************
      ***************************************************************************/

   // FontLoader{ id:digitalFont;name: DS-Digital}

    /***************************************************************************
      ***************************************************************************/


    //Logo Image and font
    Text {
        id: text1
        height: 60
        color: "#660708"
        text: qsTr("ASU Racing Team")
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        font.pixelSize: 50
        horizontalAlignment: Text.AlignHCenter
        anchors.rightMargin: 1254
        anchors.leftMargin: 156
        anchors.topMargin: 85
        font.styleName: "Bold"
        font.family: "Tahoma"
    }

    Image {
        id: image
        width: 100
        height: 100
        anchors.left: parent.left
        anchors.top: parent.top
        source: "Images/52qaM5t-_400x400-removebg-preview.png"
        anchors.leftMargin: 64
        anchors.topMargin: 65
        fillMode: Image.PreserveAspectFit
    }




    /*****************************************************************************************************
      ***************************************************************************************************/

    //FOR RPM

    CircularGauge{

        id: gauge1
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        smooth: true
        anchors.topMargin: 545
        anchors.bottomMargin: 80
        anchors.leftMargin: 1345
        anchors.rightMargin: 75
        maximumValue: 15
        stepSize: 0
        value:controller.RPM
        style: CircularGaugeStyle
        {
            id: style1
            tickmarkStepSize: 1
            labelStepSize: 1

            needle: Rectangle {
                y: outerRadius * 0.15
                implicitWidth: outerRadius * 0.03
                implicitHeight: outerRadius * 0.85
                antialiasing: true
                color:gauge1.value>=9 ?"#B92013":"#83E322"
            }


            foreground: Item {
                Rectangle {
                    width: outerRadius * 0.2
                    height: width
                    radius: width / 2
                    color: gauge1.value>=9 ?"#650801":"#349A0A"
                    anchors.centerIn: parent
                }
            }

            tickmarkLabel:  Text {
                font.pixelSize: Math.max(6, outerRadius * 0.15)
                text: styleData.value
                color: styleData.value >= 9 ? "#e34c22" : "#83E322"
                antialiasing: true
            }

            tickmark: Rectangle {
                visible: styleData.value < 9 || styleData.value % 1 == 0
                implicitWidth: outerRadius * 0.02
                antialiasing: true
                implicitHeight: outerRadius * 0.06
                color: styleData.value >= 9 ? "#e34c22" : "#83E322"
            }

            minorTickmark: Rectangle {
                visible: styleData.value < 12
                implicitWidth: outerRadius * 0.01
                antialiasing: true
                implicitHeight: outerRadius * 0.03
                color: styleData.value >= 9 ? "#e34c22" : "#e5e5e5"
            }



            background: Canvas {
                onPaint: {
                   var ctx = getContext("2d");
                       ctx.reset();

                       ctx.beginPath();
                       ctx.strokeStyle = "#e34c22";
                       ctx.lineWidth = outerRadius * 0.02;

                       ctx.arc(outerRadius, outerRadius, outerRadius - ctx.lineWidth / 2,
                           -0.05,Math.PI * 0.305, false);
                        ctx.stroke();
                  }
             }
        }

        Text {
            id: text2
            color: "#C1D9C6"
            text: "x1000/min"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            font.styleName: "Bold"
            font.family: "Verdana"
            anchors.rightMargin: 147
            anchors.leftMargin: 147
            anchors.bottomMargin: 70
            anchors.topMargin: 273
        }

        Text {
            id: text3
            color: "#63daea"
            text: controller.RPM
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 55
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 89
            anchors.leftMargin: 89
            anchors.bottomMargin: 22
            anchors.topMargin: 315
            font.italic: false
            font.bold: true
            font.family: "DS-Digital"
        }

    }



    /***************************************************************************************************
      *************************************************************************************************/


    //FOR SPEED

    CircularGauge {
        id: gauge
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        smooth: true
        anchors.leftMargin: 75
        anchors.rightMargin: 1345
        anchors.bottomMargin: 80
        anchors.topMargin: 545
        maximumValue: 160
        value:controller.speed

          style: CircularGaugeStyle {
              id: style

              tickmark: Rectangle {
                  visible:  styleData.value % 10 == 0
                  implicitWidth: outerRadius * 0.02
                  antialiasing: true
                  implicitHeight: outerRadius * 0.06
                  color: "#83E322"
              }

              minorTickmark: Rectangle {
                  visible: true
                  implicitWidth: outerRadius * 0.01
                  antialiasing: true
                  implicitHeight: outerRadius * 0.03
                  color: "#e5e5e5"
              }

              tickmarkLabel:  Text {
                  font.pixelSize: Math.max(6, outerRadius * 0.12)
                  font.bold: true
                  text: styleData.value
                  color: "#e5e5e5"
                  antialiasing: true
              }

              needle: Rectangle {
                  y: outerRadius * 0.15
                  implicitWidth: outerRadius * 0.03
                  implicitHeight: outerRadius * 0.85
                  antialiasing: true
                  color: "#83E322"
              }

              foreground: Item {
                  Rectangle {
                      width: outerRadius * 0.2
                      height: width
                      radius: width / 2
                      color: "#349A0A"
                      anchors.centerIn: parent
                  }
              }
          }

          Text {
              id: text4
              color: "#C1D9C6"
              text: "km/h"
              anchors.left: parent.left
              anchors.right: parent.right
              anchors.top: parent.top
              anchors.bottom: parent.bottom
              font.pixelSize: 22
              horizontalAlignment: Text.AlignHCenter
              font.styleName: "Bold"
              font.family: "Verdana"
              anchors.rightMargin: 147
              anchors.leftMargin: 147
              anchors.bottomMargin: 70
              anchors.topMargin: 273
          }

          Text {
              id: text5
              color: "#63daea"
              text: controller.speed
              anchors.left: parent.left
              anchors.right: parent.right
              anchors.top: parent.top
              anchors.bottom: parent.bottom
              font.pixelSize: 55
              horizontalAlignment: Text.AlignHCenter
              anchors.leftMargin: 89
              anchors.rightMargin: 89
              anchors.bottomMargin: 22
              anchors.topMargin: 315
              font.italic: false
              font.bold: true
              font.family: "DS-Digital"
          }
      }




    /***************************************************************************************************
      *************************************************************************************************/



   // GEAR


    Text {
        id: text9
        x: 75
        y: 525
        width: 62
        height: 69
        color: "#8eb1c7"
        text: controller.gear === 0 ? "R":(controller.gear === 1 ? "N": (controller.gear - 1))
        font.pixelSize: 80
        horizontalAlignment: Text.AlignHCenter
        font.family: "DS-Digital"

    }

    /***************************************************************
      *************************************************************/

    //BATTERY WARNING

    Image {
        id: image1
        x: 164
        y: 462
        width: 86
        height: 86
        source: "Images/mmm.png"
        fillMode: Image.PreserveAspectFit
        visible: (controller.battery ===1)? true : false
    }

    //OIL WARNING

    Image {
        id: image2
        x: 266
        y: 421
        width: 98
        height: 96
        source: "Images/Capture-removebg-preview.png"
        fillMode: Image.PreserveAspectFit
        visible: (controller.battery ===1)? true : false
    }

  /*  Image {
        id: image3
        y: 415
        width: 559
        height: 411
        source: "Images/fsuk21_last_wan.218-removebg-preview.png"
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        rotation: -90.000
        fillMode: Image.PreserveAspectFit

        Text {
            id: text7
            color: "#df0fe4"
            text: controller.URWheelSpeed + "\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 177
            anchors.leftMargin: 358
            anchors.bottomMargin: -6
            anchors.topMargin: 395
            font.bold: true
            font.family: "DS-Digital"
            rotation: -270
        }

        Text {
            id: text11
            color: "#eef902"
            text: controller.DRWheelSpeed + "\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 429
            anchors.leftMargin: 106
            anchors.bottomMargin: -6
            anchors.topMargin: 395
            font.family: "DS-Digital"
            font.bold: true
            rotation: -270
        }

        Text {
            id: text6
            color: "#1526a1"
            text: controller.ULWheelSpeed + "\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 177
            anchors.leftMargin: 358
            anchors.bottomMargin: 395
            anchors.topMargin: -6
            font.bold: true
            font.family: "DS-Digital"
            rotation: -270
        }

        Text {
            id: text10
            color: "#21aa00"
            text: controller.DLWheelSpeed + "\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            font.bold: false
            anchors.rightMargin: 430
            anchors.leftMargin: 100
            anchors.bottomMargin: 392
            anchors.topMargin: -10
            rotation: 90
            font.family: "DS-Digital"
        }






    }*/

    Slider {
        id: control
        width: 359
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: -10
        anchors.horizontalCenter: parent.horizontalCenter
        enabled: false
        anchors.topMargin: 243
        anchors.bottomMargin: 727
        from: -150
        to:150
        value : controller.SteeringWheel
        background: Rectangle {
                x: control.leftPadding
                y: control.topPadding + control.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: control.availableWidth
                height: implicitHeight
                radius: 2
                color: (control.value<130)&&(control.value>-130) ? "#434441" : "#5a0700"
            }
    }

    Text {
        id: text13
        y: 213
        color: (control.value<130)&&(control.value>-130) ? "#434441" : "#5a0700"
        text: control.value + "°"
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenterOffset: -10
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: text14
        x: 760
        y: 289
        color: "#b1a7a6"
        text: qsTr("-150°")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
    }

    Text {
        id: text15
        x: 1070
        y: 289
        color: "#b1a7a6"
        text: qsTr("150°")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
    }

    /********************************************************
      *******************************************************/

    //GG Diagram

    Image {
        id: image4
        x: 1352
        y: 147
        width: 294
        height: 294
        source: "Images/Picsart_22-05-19_17-22-35-286.png"
        rotation: -90
        fillMode: Image.PreserveAspectFit

        Image {
            id: image5
            x: ((controller.YtoXDiagram-20) * 7.5) + 137 //0.075
            y: ((controller.XtoYDiagram-20) * 7.5) + 137
            width: 20
            height: 20
            source: "Images/images-removebg-preview.png"
            z: 1
            fillMode: Image.PreserveAspectFit
        }

        Shape {
              ShapePath {
                  strokeColor: "red";
                  strokeWidth: 2
                  startX: 147; startY: 147
                  PathLine {

                      x:image5.x +10
                      y:image5.y +10



                  }
              }
        }


  }


    /***********************************************************************
      ********************************************************************/

    //BIG LOGO CAR

    Image {
        id: image3
        y: 345
        width: 604
        height: 557
        source: "Images/car.png"
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit

        Text {
            id: text6
            color: "#b1a7a6"
            text: controller.ULWheelSpeed +"\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 507
            anchors.leftMargin: 37
            anchors.bottomMargin: 334
            anchors.topMargin: 163
            font.bold: true
            font.family: "DS-Digital"
        }

        Text {
            id: text7
            color: "#b1a7a6"
            text: controller.DLWheelSpeed +"\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 507
            anchors.leftMargin: 37
            anchors.bottomMargin: 85
            anchors.topMargin: 412
            font.bold: true
            font.family: "DS-Digital"
        }

        Text {
            id: text10
            color: "#b1a7a6"
            text: controller.URWheelSpeed +"\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 42
            anchors.leftMargin: 502
            anchors.bottomMargin: 334
            anchors.topMargin: 163
            font.bold: true
            font.family: "DS-Digital"
        }

        Text {
            id: text11
            color: "#b1a7a6"
            text: controller.DRWheelSpeed+"\nkm/h"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 42
            anchors.leftMargin: 502
            anchors.bottomMargin: 85
            anchors.topMargin: 412
            font.bold: true
            font.family: "DS-Digital"
        }

        /***********************
          *********************/

        Gauge {
            id: gauge2
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.topMargin: 399
            anchors.bottomMargin: 53
            anchors.leftMargin: 123
            anchors.rightMargin: 433
            minorTickmarkCount: 0
            tickmarkStepSize:0
            value:controller.DLTravel
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge2.value >75 ? "#ff0000":"#a3b18a"
                    width: 15
                }
            }
        }

        Text {
            id: text12
            color: gauge2.value >75 ? "#ff0000":"#a3b18a"
            text: gauge2.value +"%"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 438
            anchors.leftMargin: 130
            anchors.bottomMargin: 160
            anchors.topMargin: 379
            font.family: "Verdana"
        }

        Gauge {
            id: gauge3
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.topMargin: 125
            anchors.bottomMargin: 327
            anchors.leftMargin: 123
            anchors.rightMargin: 433
            minorTickmarkCount: 0
            tickmarkStepSize:0
            value:controller.ULTravel
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge3.value >75 ? "#ff0000":"#a3b18a"
                    width: 15
                }
            }
        }

        Text {
            id: text8
            color: gauge3.value >75 ? "#ff0000":"#a3b18a"
            text: gauge3.value +"%"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 438
            anchors.leftMargin: 130
            anchors.bottomMargin: 434
            anchors.topMargin: 105
            font.family: "Verdana"
        }


        Gauge {
            id: gauge4
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 132
            anchors.leftMargin: 424
            anchors.bottomMargin: 327
            anchors.topMargin: 125
            minorTickmarkCount: 0
            tickmarkStepSize:0
            value:controller.URTravel
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge4.value >75 ? "#ff0000":"#a3b18a"
                    width: 15
                }
            }
        }

        Text {
            id: text16
            color: gauge4.value >75 ? "#ff0000":"#a3b18a"
            text: gauge4.value +"%"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 138
            anchors.leftMargin: 430
            anchors.bottomMargin: 434
            anchors.topMargin: 105
            font.family: "Verdana"
        }

        Gauge {
            id: gauge5
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 132
            anchors.leftMargin: 424
            anchors.bottomMargin: 53
            anchors.topMargin: 399
            minorTickmarkCount: 0
            tickmarkStepSize:0
            value:controller.DRTravel
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge5.value >75 ? "#ff0000":"#a3b18a"
                    width: 15
                }
            }
        }


        Text {
            id: text17
            color: gauge5.value >75 ? "#ff0000":"#a3b18a"
            text: gauge5.value +"%"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 138
            anchors.leftMargin: 430
            anchors.bottomMargin: 160
            anchors.topMargin: 379
            font.family: "Verdana"
        }

        Gauge {
            id: gauge6
            value:controller.SpeedThrottle
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 77
            anchors.leftMargin: 479
            anchors.bottomMargin: 151
            anchors.topMargin: 238
            minorTickmarkCount: 0
            tickmarkStepSize:0

            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge6.value >75 ? "#ff0000":"#a3b18a"
                    width: 15
                }
            }
        }

        Text {
            id: text18
            color: gauge6.value >75 ? "#ff0000":"#a3b18a"
            text: gauge6.value +"%"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 25
            anchors.leftMargin: 533
            anchors.bottomMargin: 226
            anchors.topMargin: 313
            font.family: "Verdana"
        }



    }

    Text {
        id: text19
        x: 129
        y: 327
        width: 90
        height: 74
        color: "#e11477"
        text: "118 °C \n" + "ECT"
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        font.styleName: "Regular"
        font.family: "Tahoma"
        clip: true
    }

    Text {
        id: text20
        x: 289
        y: 278
        color: "#4fd133"
        text: (11/10) + "\nMAP"
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: text21
        x: 406
        y: 334
        color: "#fdef3d"
        text: "0.760 " + "\nLambda"
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: text22
        x: 1352
        y: 469
        color: "#ffffff"
        text: "Ax: " + (controller.YtoXDiagram-20)
        font.pixelSize: 25

        Text {
            id: text23
            x: 218
            y: 0
            color: "#fffefe"
            text: "Ay: " + (controller.XtoYDiagram-20)
            font.pixelSize: 25
        }
    }

  /*  Gauge {
        id: gauge3
        x: 793
        y: 500
        width: 35
        height: 85
        rotation: 0
        tickmarkStepSize: 0
        value:controller.SpeedThrottle/10
        style: GaugeStyle {
            valueBar: Rectangle {
                color: "grey"
                implicitWidth: 15
            }

        }

        Text {
            id: text16
            x: 24
            y: -15
            text: controller.SpeedThrottle/10 +"%"
            font.pixelSize: 14
            horizontalAlignment: Text.AlignHCenter

        }
    }

    Gauge {
        id: gauge4
        x: 1068
        y: 500
        width: 35
        height: 85
        tickmarkStepSize: 0
        value:controller.SpeedThrottle/10
        style: GaugeStyle {
            valueBar: Rectangle {
                color: "grey"
                implicitWidth: 15
            }

        }

        Text {
            id: text19
            x: 18
            y: -12
            text: controller.SpeedThrottle/10 +"%"
            font.pixelSize: 14
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Gauge {
        id: gauge5
        x: 793
        y: 745
        width: 35
        height: 85
        tickmarkStepSize: 0
        value :controller.SpeedThrottle/10
        style: GaugeStyle {
            valueBar: Rectangle {
                color: "grey"
                implicitWidth: 15
            }

        }

        Text {
            id: text17
            x: 17
            y: -11
            text: controller.SpeedThrottle/10 +"%"
            font.pixelSize: 14
            horizontalAlignment: Text.AlignHCenter
        }
    }

   Gauge {
       id: gauge6
       x: 1068
       y: 745
       width: 35
       height: 85
       tickmarkStepSize: 0
       value:controller.SpeedThrottle/10
       style: GaugeStyle {
           valueBar: Rectangle {
               color: "grey"
               implicitWidth: 15
           }

       }

       Text {
           id: text18
           x: 18
           y: -11
           text: controller.SpeedThrottle/10 +"%"
           font.pixelSize: 14
           horizontalAlignment: Text.AlignHCenter
       }
   }

   Gauge {
       id: gauge2
       x: 1048
       y: 623
       value:66
       width: 35
       height: 100
       tickmarkStepSize: 0
       style: GaugeStyle {
           valueBar: Rectangle {
               color: "orange"
               implicitWidth: 15
           }

       }

       Text {
           id: text12
           x: 17
           y: -13
           text: "35%"
           font.pixelSize: 15
           horizontalAlignment: Text.AlignHCenter
           color: "orange"
       }
   }*/


}










/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/
