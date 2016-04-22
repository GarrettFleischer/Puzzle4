import QtQuick 2.5
import QtQuick.Controls 1.4
import Qt.labs.settings 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Traffic Light")

    Rectangle
    {
        id: big_wrapper
        anchors.fill: parent

        Rectangle
        {
            id: rect_traffic_light_head
            anchors.horizontalCenter: big_wrapper.horizontalCenter
            anchors.verticalCenter: big_wrapper.verticalCenter

            height: parent.height * .9;
            width: parent.width/3;
            border.color: "brown"


            Timer
            {
                interval: 2000
                repeat: true
                running: true
                triggeredOnStart: false

                onTriggered: {
                    TrafficLight.toggle_light(TrafficLight.light = ((TrafficLight.light + 1) % 3));
                }
            }



            Rectangle
            {
                id: rect_red_light
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
                height: 100;
                width: 100;
                radius: width/2;
                border.width: 10
                border.color: "black"
                color: TrafficLight.light === 0 ? TrafficLight.get_color(0) : "black"
            }

            Rectangle
            {
                id: rect_yellow_light
                anchors.top: rect_red_light.bottom
                anchors.topMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
                height: 100;
                width: 100;
                radius: width/2;
                border.width: 10
                border.color: "black"
                color: TrafficLight.light === 1 ? TrafficLight.get_color(1) : "black"
            }

            Rectangle
            {
                id: rect_green_light
                anchors.top: rect_yellow_light.bottom
                anchors.topMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
                height: 100;
                width: 100;
                radius: width/2;
                border.color: "black"
                border.width: 10
                color: TrafficLight.light === 2 ? TrafficLight.get_color(2) : "black"
            }
        }

    }
}
