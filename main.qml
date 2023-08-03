import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.15
import QtQuick.Extras.Private 1.0
import QtQuick.Shapes 1.15
import QtCharts 2.3
import Qt3D.Input 2.15



Window {
    id:mainWaindow
    width: 1900
    height: 1010
    visible: true
    //visibility: "Maximized"
    color: "#0f2a3e"
    title: qsTr("ASU Racing Team")
    property real xDiagram: ((controller.XtoYDiagram / 100) - 360)
    property real yDiagram: ((controller.YtoXDiagram / 100) - 360)
    property real minX: 0
    property real maxX: 0
    property real maxY: 0
    property real minY: 0
    property int  timeAnimation: 150

    onXDiagramChanged:  {
        if((xDiagram >=-2) && (xDiagram<=2)) {
           maxX = (maxX < xDiagram) ? xDiagram : maxX
           minX = (minX > xDiagram) ? xDiagram : minX
        }
    }

    onYDiagramChanged:  {
        maxY = (maxY < yDiagram) ? yDiagram : maxY
        minY = (minY > yDiagram) ? yDiagram : minY
    }



    /***************************************************************************
      ***************************************************************************/

   // FontLoader{ id:digitalFont;name: DS-Digital}

    /***************************************************************************
      ***************************************************************************/


    //Logo Image and font

    Image {
        id: image
        width: 100
        height: 100
        anchors.left: parent.left
        anchors.top: parent.top
        source: "Images/52qaM5t-_400x400-removebg-preview.png"
        anchors.leftMargin: 75
        anchors.topMargin: 78
        fillMode: Image.PreserveAspectFit
    }




    /*****************************************************************************************************
      ***************************************************************************************************/

    /*----------------------------- RPM ------------------------------------------*/

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
        value: controller.RPM / 1000
        /*Behavior on value {
            NumberAnimation {
                duration: timeAnimation
                easing.type:  Easing.InOutQuad
            }
        }*/
        Behavior on value {
            SmoothedAnimation {
                easing.type:  Easing.InOutQuad
                velocity: 30
            }
        }
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


    /*------------------------------- Speed -------------------------------------*/

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
        value:controller.speed / 100
        Behavior on value {
            SmoothedAnimation {
                easing.type:  Easing.InOutQuad
                velocity: 320
            }
        }
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
              text: Math.floor(gauge.value)
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



   /*------------------------------- Gear -------------------------------*/


    Text {
        id: text9
        x: 75
        y: 525
        width: 62
        height: 69
        color: "#8eb1c7"
        text: controller.gear === 0 ? "D": "N"
        font.pixelSize: 80
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"

    }

    /***************************************************************
      *************************************************************/

    /*----------------------- Battery Voltage -------------------------------*/

    Image {
        id: image1
        x: 146
        y: 438
        width: 86
        height: 86
        visible: true
        source: "Images/mmm.png"
        fillMode: Image.PreserveAspectFit

        Text {
            id: text24
            y: 67
            visible: true
            color: "#f30f0f"
            text: (controller.battery / 100).toFixed(2)
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    /*----------------------------- Steering wheel ---------------------------*/

/*
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
        Behavior on value {
            NumberAnimation {
                duration: timeAnimation
                easing.type:  Easing.InOutQuad
            }
        }
        background: Rectangle {
                x: control.leftPadding
                y: control.topPadding + control.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: control.availableWidth
                height: implicitHeight
                radius:2
                color: (control.value<130)&&(control.value>-130) ? "#16ff03" : "#ff0000"
            }
        handle: Rectangle {
            width: 15
            height: control.availableHeight + control.topPadding + control.bottomPadding
            radius: 2
            color: (control.value<130)&&(control.value>-130) ? "#16ff03" : "#ff0000"
        }
    }

    Text {
        id: text13
        y: 213
        color: (control.value<130)&&(control.value>-130) ? "#16ff03" : "#ff0000"
        text: (control.value).toFixed(0) + "°"
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
        color: "#f3f3f3"
        text: qsTr("-150°")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
    }

    Text {
        id: text15
        x: 1070
        y: 289
        color: "#f3f3f3"
        text: qsTr("150°")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
    }*/
     /*--------------------------------------------------------------------------*/
    /********************************************************
      *******************************************************/

    /*------------------------------ GG Diagram ----------------------------*/

    Image {
        id: image4
        x: 1479
        y: 78
        width: 294
        height: 294
        source: "Images/Picsart_22-05-19_17-22-35-286.png"
        rotation: -90
        fillMode: Image.PreserveAspectFit

        Image {
            id: image5
            x: (yDiagram * 75) +  137    // hena y
            y: (xDiagram  * 75) +  137
            width: 20
            height: 20
            source: "Images/images-removebg-preview.png"
            z: 1
            fillMode: Image.PreserveAspectFit
            Behavior on x {
                SmoothedAnimation {
                    easing.type:  Easing.InOutQuad
                    velocity: 588
                }
            }
            Behavior on y {
                SmoothedAnimation {
                    easing.type:  Easing.InOutQuad
                    velocity: 588
                }
            }
        }

        /*Shape {
              ShapePath {
                  strokeColor: "red";
                  strokeWidth: 2
                  startX: 147; startY: 147
                  PathLine {
                      x:image5.x +10
                      y:image5.y +10
              }
          }
      }*/


  }

    Text {
        id: text22
        x: 1479
        y: 378
        color: "#ffffff"
        text: "Ax " + xDiagram.toFixed(2)
        font.pixelSize: 25

        Text {
            id: text23
            x: 218
            y: 0
            color: "#fffefe"
            text: "Ay " + yDiagram.toFixed(2)
            font.pixelSize: 25
        }
    }

    Text {
        id: text25
        x: 1514
        y: 414
        color: "#16ff03"
        text: maxX.toFixed(2)
        font.pixelSize: 25
    }

    Text {
        id: text26
        x: 1514
        y: 450
        color: "#ff0000"
        text: minX.toFixed(2)
        font.pixelSize: 25
    }

    Text {
        id: text27
        x: 1723
        y: 414
        color: "#16ff03"
        text: maxY.toFixed(2)
        font.pixelSize: 25
    }

    Text {
        id: text28
        x: 1723
        y: 450
        color: "#ff0000"
        text: minY.toFixed(2)
        font.pixelSize: 25
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

        /*----------------------------- Wheels RPM ----------------------*/

        Text {
            id: text6
            color: "#f3f3f3"
            text: controller.ULWheelSpeed +"\nRPM"
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
            color: "#f3f3f3"
            text: controller.DLWheelSpeed +"\nRPM"
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
            color: "#f3f3f3"
            text: controller.URWheelSpeed +"\nRPM"
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
            color: "#f3f3f3"
            text: controller.DRWheelSpeed+"\nRPM"
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

        /*-------------------------------- Travel Sensors -----------------------*/

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
            Behavior on value {
                NumberAnimation {
                    easing.type:  Easing.InOutQuad
                    duration:  200
                }
            }
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge2.value>75 ? (gauge2.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
                    width: 15
                }
            }
        }

        Text {
            id: text12
            color: gauge2.value>75 ? (gauge2.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
            text: gauge2.value.toFixed(0) +"%"
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
            Behavior on value {
                NumberAnimation {
                    easing.type:  Easing.InOutQuad
                    duration:  200
                }
            }
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge3.value>75 ? (gauge3.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
                    width: 15
                }
            }
        }

        Text {
            id: text8
            color: gauge3.value>75 ? (gauge3.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
            text: gauge3.value.toFixed(0) +"%"
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
            Behavior on value {
                NumberAnimation {
                    easing.type:  Easing.InOutQuad
                    duration:  200
                }
            }
            /*Behavior on value {
                                        SmoothedAnimation {
                                            velocity: 200
                                        }
                                    }*/
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge4.value>75 ? (gauge4.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
                    width: 15
                }
            }
        }

        Text {
            id: text16
            color: gauge4.value>75 ? (gauge4.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
            text: (gauge4.value).toFixed(0) +"%"
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
            Behavior on value {
                NumberAnimation {
                    easing.type:  Easing.InOutQuad
                    duration:  200
                }
            }
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge5.value>75 ? (gauge5.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
                    width: 15
                }
            }
        }


        Text {
            id: text17
            color: gauge5.value>75 ? (gauge5.value > 85 ?"#ff0000" :"#ff8c00"):"#16ff03"
            text: gauge5.value.toFixed(0) +"%"
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


        /*---------------------- Speed Throtle -------------------------*/

        Gauge {

            property real targetValue: controller.SpeedThrottle
            property real gaugeValue: targetValue
            id: gauge6
            value:controller.SpeedThrottle
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            antialiasing: true
            anchors.rightMargin: 77
            anchors.leftMargin: 479
            anchors.bottomMargin: 151
            anchors.topMargin: 238
            minorTickmarkCount: 0
            tickmarkStepSize:0
            Behavior on value {
                SmoothedAnimation {
                    easing.type:  Easing.InOutQuad
                    velocity: 200
                }
            }
           /* Behavior on value {
                            SmoothedAnimation {
                                velocity: 180
                            }
                        }*/
            style :GaugeStyle {
                valueBar: Rectangle {
                    color: gauge6.value >40 ? (gauge6.value > 80 ?"#ff0000" :"#ff8c00"):"#16ff03"
                    width: 15
                }
            }
        }

        Text {
            id: text18
            color: gauge6.value >40 ? (gauge6.value > 80 ?"#ff0000" :"#ff8c00"):"#16ff03"
            text: "TPS\n"+" " +(gauge6.value).toFixed(0) +"%"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            anchors.rightMargin: 25
            anchors.leftMargin: 533
            anchors.bottomMargin: 226
            anchors.topMargin: 313
            font.family: "Verdana"
        }



    }


    /*---------------------------- ECT ---------------------------------*/

    Text {
        id: text19
        x: 256
        y: 450
        width: 90
        height: 74
        color:  controller.ECT>85 ? (controller.ECT > 95 ?"#ff0000" :"#ff8c00"):"#16ff03"
        text: controller.ECT + "°C \n" + "ECT"
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        font.styleName: "Regular"
        font.family: "Tahoma"
        clip: true
    }


 /*--------------------------------- Steering wheel -----------------------------*/

    Image {
        id: image2
        x: 833
        y: 173
        width: 234
        height: 166
        visible: true
        source: "Images/Steering wheel.png"
        fillMode: Image.PreserveAspectFit
        rotation: controller.SteeringWheel - 180
        Behavior on rotation {
            SmoothedAnimation {
                easing.type:  Easing.InOutQuad
                velocity: 250
            }
        }
    }

    Text {
        id: text13
        x: 939
        y: 355
        color: ((controller.SteeringWheel-180)<130)&&((controller.SteeringWheel-180)>-130) ? "#16ff03" : "#ff0000"
        text: (controller.SteeringWheel - 180).toFixed(0) + "°"
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenterOffset: 1
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    /*-------------------------------------------------------------------*/

    /*------------------------- Break Switch ----------------------------*/

    Text {
        id: text15
        x: 367
        y: 494
        visible: (controller.breaking === 1) ? 1 : 0
        color: "#ff0000"
        text: qsTr("Break")
        font.pixelSize: 25
        font.bold: true
    }

    /*------------------------ Fuel Switch ---------------------------*/

    Text {
        id: text1
        x: 490
        y: 525
        visible: (controller.fuel === 1) ? 1 : 0
        color: "#ff0000"
        text: qsTr("Fuel\nLow")
        font.pixelSize: 25
        font.bold: true
    }


    /*-------------------------- Slipping angle -------------------------*/

    Text {
        id: text20
        color:(controller.Sliping === 1) ? "#ff0000" : "#16ff03"
        text: (controller.Sliping === 1) ? qsTr("\u26A0Sliping\u26A0") : qsTr("No Sliping")
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        anchors.leftMargin: 890
        anchors.rightMargin: 882
        anchors.topMargin: 883
        font.bold: true
    }







    /*----------------------------- Mapping -----------------------------*/

   /* ChartView {
        id: chartView
        anchors {
            fill: parent
            leftMargin: 8
            rightMargin: 1083
            bottomMargin: 596
            topMargin: 14
        }
        antialiasing: true
        legend.visible: false
        property var dataPoints: []

        property var speed: controller.speed

        onSpeedChanged: {
            series.append(7,7);
            chartView.dataPoints.push(100);
        }

        ScatterSeries {
            id: series


            Label {
                id: label1
                x: 0.5
                y: 0.5
                text: qsTr("Label")
                z: 1
                visible: true
            }

            onHovered: {

                console.log("onHovered: " + chartView.dataPoints[0]  );
                label.textUpdated(chartView.dataPoints[0]);
                //chartView.dataPoints.indexOf(series.at(index).y);
            }
        }

        Label {
            id: label
            x: 84
            y: 351
            text: qsTr("Label")
            font.pointSize: 15
            z: 1

            // Signal handler for updating the text
            signal textUpdated(string newText)

            onTextUpdated: {
                // Handle the text update
                label.text = "Speed = "+newText;
            }

            signal coordinatesUpdated(double newX, double newY)

            // Update the x and y coordinates
            onCoordinatesUpdated: {
                label.x = newX;
                label.y = newY;
            }

        }
    }*/




    /*---------------------------------------------------------------------*/

}














/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
