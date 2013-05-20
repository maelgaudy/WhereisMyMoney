import QtQuick 2.0

Rectangle {
    id: baseRect

    property color baseColor: "lightGrey"
    property int defaultMargin: 5
    property int defaultRadius: 6

    function setBarPosition(barNb, position) {

        if(barNb === 1) {
             resizeBar1.x = position
        } else if(barNb === 2) {
            resizeBar2.x = position
        } else {
            console.log("No Such bar :", barNb)
        }
    }
    function getBarPosition(barNb) {
        var position
        if(barNb === 1) {
            position = resizeBar1.x
        } else if(barNb === 2) {
            position = resizeBar2.x
        } else {
            position = -1
        }

        return position
    }

    width: 360
    height: 360
    color: baseColor

    Rectangle {
        id: contentRect

        anchors.fill: parent
        anchors.leftMargin: baseRect.defaultMargin
        anchors.rightMargin: baseRect.defaultMargin
        anchors.topMargin: baseRect.defaultMargin
        anchors.bottomMargin: baseRect.defaultMargin
        color: "transparent"

        Rectangle {
            id: accountsRect

            anchors.left: parent.left
            anchors.right: resizeBar1.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            radius: baseRect.defaultRadius

            ListView {
                id: accountListView

                anchors.fill: parent
                clip: true
                focus: true
                highlightMoveDuration: 300
                highlightFollowsCurrentItem: true

                model: accountList
                delegate: Rectangle {

                    width: parent.width
                    height: 25
                    color: "transparent"

                    Text {
                        id: accountNameRect

                        text: modelData
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }

                    MouseArea {

                        anchors.fill: parent
                        onClicked: accountListView.currentIndex = index
                    }
                }

                highlight: Rectangle { color: "lightsteelblue"; width: parent.width ; radius: 6}
            }
        }

        ResizeBar {
            id: resizeBar1

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            color: baseRect.baseColor
            maxX: resizeBar2.x - resizeBar2.width
        }

        Rectangle {
            id: oneAccountViewRect

            anchors.left: resizeBar1.right
            anchors.right: resizeBar2.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            radius: baseRect.defaultRadius
        }

        ResizeBar {
            id: resizeBar2

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            color: baseRect.baseColor
            maxX: parent.width - baseRect.defaultMargin
            minX: resizeBar1.x + resizeBar1.width
        }

        Rectangle {
            id: statsViewRect

            anchors.left: resizeBar2.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            radius: baseRect.defaultRadius
        }
    }
}
