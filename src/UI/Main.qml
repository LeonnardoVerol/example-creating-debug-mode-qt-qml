import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Example Creating Debug Mode in QT/QML")
    color: QT_DEBUG ? "yellow" : "green"

    Text {
        id: name
        anchors.centerIn: parent
        text: QT_DEBUG ? "Debug Mode" : "Release Mode"
        font.pixelSize: 28
    }
}
