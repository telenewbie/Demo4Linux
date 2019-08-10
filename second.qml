import QtQuick 2.0
import QtQuick.Controls 1.2

import "qrc:/testJs.js" as JS

Rectangle{
    id: view
    width: 640
    height: 480
    property var viewData
    Button {
        id:test
        x: 8
        y: 8
        text: "打印传递过来的值"
        onClicked: {
            print(viewData[0])
        }
    }
    Button {
        id:des
        y: 8
        text: "关闭"
        anchors.left: test.right
        anchors.leftMargin: 10
        onClicked: {
            view.destroy();
        }
    }

    Button {
        id:invokeJs
        y: 8
        text: "调用JS的函数"
        anchors.left: des.right
        anchors.leftMargin: 10
        onClicked: {
            JS.func()
        }
    }

    Text {
        id: text1
        x: 240
        y: 59
        text: qsTr("Text")
        font.pixelSize: 12
    }
}
