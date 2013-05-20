import QtQuick 2.0

Rectangle {
    id: resizeRect

    property int maxX: 25
    property int minX: 0

    width: 4
    height: 100

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        anchors.leftMargin: -1
        anchors.rightMargin: -1
        hoverEnabled: true
        drag.target: resizeRect
        drag.axis: Drag.XAxis
        drag.maximumX: resizeRect.maxX
        drag.minimumX: resizeRect.minX

        onEntered: cursorShape = Qt.SizeHorCursor
        onExited: cursorShape = Qt.ArrowCursor
    }
}
