// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : Enumeration.cs
// 파일 설명    : DiagramModeler에서 사용하는 Enumeration들을 정의
// 최초 작성자  : 노현종(neoswir@miracom.co.kr)
// 최초 작성일  : 2007년 5월 02일 
// 최종 수정일  : 2007년 5월 08일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 02 : [노현종] 최초 작성
//       05. 08 : [노현종] 작성 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;

namespace Miracom.Common.DiagramModeler
{

    #region <<< [ In Use       ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    public enum ConnectionRuleType
    {
        Default,
        Allow,
        Prohibit,
        Mix
    }

    /// <summary>
    /// UML 관계를 설명합니다.
    /// </summary>
    public enum ArrowStyle
    {
        /// <summary>
        /// Composition 관계 입니다.
        /// </summary>
        Composition,

        /// <summary>
        /// Aggreagation 관계 입니다
        /// </summary>
        Aggregation,

        /// <summary>
        /// 일반화 관계 입니다.
        /// </summary>
        Generalization,

        /// <summary>
        /// 실재화 관계 입니다.
        /// </summary>
        Realization,

        /// <summary>
        /// 종속 관계 입니다.
        /// </summary>
        Dependency,

        /// <summary>
        /// 중첩(Nesting) 관계 입니다.
        /// </summary>
        Nesting,

        /// <summary>
        /// 주석 관계 입니다.
        /// </summary>
        None
    }

    /// <summary>
    /// Node Shape Style 설명합니다.
    /// </summary>
    public enum ShapeStyle
    {
        /// <summary>
        /// 
        /// </summary>
        CogWheel,
        /// <summary>
        /// 
        /// </summary>
        AlternateProcess,

        /// <summary>
        /// 
        /// </summary>
        Card,

        /// <summary>
        /// 
        /// </summary>
        Collate,

        /// <summary>
        /// 
        /// </summary>
        Connector,

        /// <summary>
        /// 십자가를 상징하는 도형을 나타냅니다.
        /// </summary>
        Cross,

        /// <summary>
        /// 
        /// </summary>
        Custom,

        /// <summary>
        /// 테이터를 상징하는 도형을 나타냅니다
        /// </summary>
        Data,

        /// <summary>
        /// 결정을 상징하는 도형을 나타냅니다
        /// </summary>
        Decision,

        /// <summary>
        /// Delay를 상징하는 도형을 나타냅니다.
        /// </summary>
        Delay,

        /// <summary>
        /// Direct Access 저장소를 상징하는 도형을 나타냅니다
        /// </summary>
        DirectAccessStorage,

        /// <summary>
        /// Display를 상징하는 도형을 나타냅니다.
        /// </summary>
        Display,

        /// <summary>
        /// 문서를 상징하는 도형을 나타냅니다
        /// </summary>
        Document,

        /// <summary>
        /// 타원형을 나타냅니다.
        /// </summary>
        Ellipse,

        /// <summary>
        /// 추출을 상징하는 도형을 나타냅니다.
        /// </summary>
        Extract,

        /// <summary>
        /// 6각형을 나타냅니다
        /// </summary>
        Hexagon,

        /// <summary>
        /// 내부 저장소를 상징하는 도형을 나타냅니다.
        /// </summary>
        InternalStorage,

        /// <summary>
        /// 
        /// </summary>
        Losange,

        /// <summary>
        /// 자기디스트를 상징하는 도형을 나타냅니다.
        /// </summary>
        MagneticDisk,

        /// <summary>
        /// 수동 입력을 상징하는 도형을 나타냅니다.
        /// </summary>
        ManualInput,

        /// <summary>
        /// 수동 작업을 상징하는 도형을 나타냅니다.
        /// </summary>
        ManualOperation,

        /// <summary>
        /// 병합을 상징하는 도형을 나타냅니다.
        /// </summary>
        Merge,

        /// <summary>
        /// 다중문서를 상징하는 도형을 나타냅니다
        /// </summary>
        MultiDocument,

        /// <summary>
        /// 8각형을 나타냅니다
        /// </summary>
        Octogon,

        /// <summary>
        /// 
        /// </summary>
        OffPageConnection,

        /// <summary>
        /// OR를 상징하는 도형을 나타냅니다.
        /// </summary>
        Or,

        /// <summary>
        /// OR Gate를 상징하는 도형을 나타냅니다.
        /// </summary>
        OrGate,

        /// <summary>
        /// 5각형을 나타냅니다.
        /// </summary>
        Pentagon,

        /// <summary>
        /// Predefined Process를 상징하는 도형을 나타냅니다.
        /// </summary>
        PredefinedProcess,

        /// <summary>
        /// 
        /// </summary>
        Preparation,

        /// <summary>
        /// 
        /// </summary>
        Process,

        /// <summary>
        /// 
        /// </summary>
        ProcessIso9000,

        /// <summary>
        /// 
        /// </summary>
        PunchedTape,

        /// <summary>
        /// 사각형을 나타냅니다.
        /// </summary>
        Rectangle,

        /// <summary>
        /// 
        /// </summary>
        RectEdgeBump,

        /// <summary>
        /// 
        /// </summary>
        RectEdgeEtched,

        /// <summary>
        /// 
        /// </summary>
        RectEdgeRaised,

        /// <summary>
        /// 
        /// </summary>
        RectEdgeSunken,

        /// <summary>
        /// 둥그스름한 사각형을 나타냅니다.
        /// </summary>
        RoundRect,

        /// <summary>
        /// 순차 접근 저장소를 상징하는 도형을 나타냅니다.
        /// </summary>
        SequentialAccessStorage,

        /// <summary>
        /// 저장된 데이터를 상징하는 도형을 나타냅니다.
        /// </summary>
        StoredData,

        /// <summary>
        /// SummingJunction을 상징하는 도형을 나타냅니다.
        /// </summary>
        SummingJunction,

        /// <summary>
        /// 정렬을 상징하는 도형을 나타냅니다.
        /// </summary>
        Sort,

        /// <summary>
        /// 
        /// </summary>
        Termination,

        /// <summary>
        /// 전송을 상징하는 도형을 나타냅니다.
        /// </summary>
        Transport,

        /// <summary>
        /// 삼각형을 나타냅니다.
        /// </summary>
        Triangle,

        /// <summary>
        /// 
        /// </summary>
        TriangleRectangle
    }

    /// <summary>
    /// 수직정렬을 설명합니다.
    /// </summary>
    public enum VerticalAlingment
    {
        /// <summary>
        /// 상단
        /// </summary>
        Top,

        /// <summary>
        /// 중단
        /// </summary>
        Middle,

        /// <summary>
        /// 하단
        /// </summary>
        Bottom
    }

    /// <summary>
    /// 수평정렬을 설명합니다
    /// </summary>
    public enum HorizontalAlignment
    {
        /// <summary>
        /// 왼쪽
        /// </summary>
        Left,

        /// <summary>
        /// 가운데
        /// </summary>
        Center,

        /// <summary>
        /// 오른쪽
        /// </summary>
        Right
    }

    /// <summary>
    /// Link를 Draw 하는데 사용되는 Style을 설명합니다.
    /// </summary>
    public enum LineStyle
    {
        /// <summary>
        /// 일련의 연결된 선을 나타냅니다
        /// </summary>
        Polyline,

        /// <summary>
        /// 곡선으로 표현된 선을 나타냅니다.
        /// </summary>
        PolyCurveline,

        /// <summary>
        /// 
        /// </summary>
        Singleline,

        /// <summary>
        /// 
        /// </summary>
        SigleCurveline

     }

     /// <summary>
     /// Node 상의 Text나 Image의 위치를 설명합니다.
     /// </summary>
     public enum Alignment
     {
         /// <summary>
         /// 좌측정렬, 상단을 나타냅니다.
         /// </summary>
         LeftJustifyTOP,

         /// <summary>
         /// 좌측정렬, 중단을 나타냅니다.
         /// </summary>
         LeftJustifyMIDDLE,

         /// <summary>
         /// 좌측정렬, 하단을 나타냅니다.
         /// </summary>
         LeftJustifyBOTTOM,

         /// <summary>
         /// 우측정렬, 상단을 나타냅니다.
         /// </summary>
         RightJustifyTOP,

         /// <summary>
         /// 우측정렬, 중단을 나타냅니다.
         /// </summary>
         RightJustifyMIDDLE,

         /// <summary>
         /// 우측정렬, 하단을 나타냅니다.
         /// </summary>
         RightJustifyBOTTOM,

         /// <summary>
         /// 가운데정렬, 상단을 나타냅니다.
         /// </summary>
         CenterTOP,

         /// <summary>
         /// 가운데정렬, 중단을 나타냅니다.
         /// </summary>
         CenterMIDDLE,

         /// <summary>
         /// 가운데정렬, 하단을 나타냅니다.
         /// </summary>
         CenterBOTTOM
     }

     /// <summary>
     /// Grid의 Drawing Style을 설명합니다.
     /// </summary>
     public enum GridStyle
     {
         /// <summary>
         /// 한 Pixel의 점들로 Grid를 Draw합니다
         /// </summary>
         Pixels,

         /// <summary>
         /// Line들로 Grid를 Draw합니다.
         /// </summary>
         Lines,

         /// <summary>
         /// 점선으로 Grid를 Draw합니다.
         /// </summary>
         DottedLines
     }


    #endregion


    #region <<< [ Candidate    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
     
    ///// <summary>
    /////  Diagram의 변화 Action 을 설명합니다.
    ///// </summary>
    //public enum Action
    //{
    //    /// <summary>
    //    /// Link의 AdjustOrg 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    AdjustOrg,

    //    /// <summary>
    //    /// Link의 AdjustDst 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    AdjustDst,

    //    /// <summary>
    //    /// Node의 Alinement 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Alignment,

    //    /// <summary>
    //    /// Link의 ArrowOrg 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ArrowOrg,

    //    /// <summary>
    //    /// Link의 ArrowMid 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ArrowMid,

    //    /// <summary>
    //    /// Link의 ArrowDst 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ArrowDst,

    //    /// <summary>
    //    /// Node의 AttachmentStyle 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    AttachmentStyle,

    //    /// <summary>
    //    /// Node의 AutoSize 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    AutoSize,

    //    /// <summary>
    //    /// Element의 BackMode 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    BackMode,

    //    /// <summary>
    //    /// Nodes Collection이 Clear된 상태입니다.
    //    /// </summary>
    //    ClearNodes,

    //    /// <summary>
    //    /// Node의 Links Collection이 Clear된 상태입니다.
    //    /// </summary>
    //    ClearLinks,

    //    /// <summary>
    //    /// Link의 ConnectionStyleDst 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ConnectionStyleDst,

    //    /// <summary>
    //    /// Link의 ConnectionStyleOrg 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ConnectionStyleOrg,

    //    /// <summary>
    //    /// Link의 Custom EndCap 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    CustomEndCap,

    //    /// <summary>
    //    /// Link의 Custom StartCap 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    CustomStartCap,

    //    /// <summary>
    //    /// Element의 DashStyle 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    DashStyle,

    //    /// <summary>
    //    /// 선택된 Element 들이 삭제된 상태입니다.
    //    /// </summary>
    //    DeleteSel,

    //    /// <summary>
    //    /// Node의 Dock 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Dock,

    //    /// <summary>
    //    /// Element의 DrawColor 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    DrawColor,

    //    /// <summary>
    //    /// Element의 DrawWidth 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    DrawWidth,

    //    /// <summary>
    //    /// Link의 Destination Node가 변경된 상태입니다.
    //    /// </summary>
    //    Dst,

    //    /// <summary>
    //    /// Link의 EndCap 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    EndCap,

    //    /// <summary>
    //    /// Node의 FillColor 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    FillColor,

    //    /// <summary>
    //    /// Element의 Font 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Font,

    //    /// <summary>
    //    /// Node의 Gradient 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Gradient,

    //    /// <summary>
    //    /// Node의 GradientColor 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    GradientColor,

    //    /// <summary>
    //    /// Node의 GradientColor 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    GradientMode,

    //    /// <summary>
    //    /// Element의 Hidden 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Hidden,

    //    /// <summary>
    //    /// Element의 HighlightChildren 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    HighlightChildren,

    //    /// <summary>
    //    /// Node의 ImageIndex 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ImageIndex,

    //    /// <summary>
    //    /// Node의 ImageLocation 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ImageLocation,

    //    /// <summary>
    //    /// Node의 ImagePosition 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    ImagePosition,

    //    /// <summary>
    //    /// Node의 InLinkable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    InLinkable,

    //    /// <summary>
    //    /// Link의 Jump 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Jump,

    //    /// <summary>
    //    /// Node의 LabelEdit 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    LabelEdit,

    //    /// <summary>
    //    /// Link의 Line 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Line,

    //    /// <summary>
    //    /// Link가 생성된 상태입니다.
    //    /// </summary>
    //    LinkAdd,

    //    /// <summary>
    //    /// Link가 이동된 상태입니다.
    //    /// </summary>
    //    LinkMove,

    //    /// <summary>
    //    /// Link가 삭제된 상태입니다.
    //    /// </summary>
    //    LinkRemove,

    //    /// <summary>
    //    /// Link가 Stretch된 상태입니다.
    //    /// </summary>
    //    LinkStretch,

    //    /// <summary>
    //    /// Element의 Logical 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Logical,

    //    /// <summary>
    //    /// 선택된 Element이 이동된 상태입니다.
    //    /// </summary>
    //    MoveElements,

    //    /// <summary>
    //    /// Node가 생성된 상태입니다.
    //    /// </summary>
    //    NodeAdd,

    //    /// <summary>
    //    /// Node가 이동된 상태입니다.
    //    /// </summary>
    //    NodeMove,

    //    /// <summary>
    //    /// Node가 이동되거나 Size가 변경된 상태입니다.
    //    /// </summary>
    //    NodeMoveAndSize,

    //    /// <summary>
    //    /// Node가 삭제된 상태입니다.
    //    /// </summary>
    //    NodeRemove,

    //    /// <summary>
    //    /// Node가 Resize된 상태입니다.
    //    /// </summary>
    //    NodeResize,

    //    /// <summary>
    //    /// Action이 없는 상태입니다.
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// Link의 Origin Node가 변경된 상태입니다.
    //    /// </summary>
    //    Org,

    //    /// <summary>
    //    /// Link의 OrientedText 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    OrientedText,

    //    /// <summary>
    //    /// Node의 OutLinkable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    OutLinkable,

    //    /// <summary>
    //    /// Element의 OwnerDraw 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    OwnerDraw,

    //    /// <summary>
    //    /// Node의 Parent 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Parent,

    //    /// <summary>
    //    /// Link의 Points 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Points,

    //    /// <summary>
    //    /// Deserialization Action이 발생한 상태입니다.
    //    /// </summary>
    //    ReadXml,

    //    /// <summary>
    //    /// Element의 RemoveChildren 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    RemoveChildren,

    //    /// <summary>
    //    /// Link가 Reverse된 상태입니다.
    //    /// </summary>
    //    Reverse,

    //    /// <summary>
    //    /// Link의 Rigid 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Rigid,

    //    /// <summary>
    //    /// Element의 Selectable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Selectable,

    //    /// <summary>
    //    /// Node의 Shape 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Shadow,

    //    /// <summary>
    //    /// Node의 Shape 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Shape,

    //    /// <summary>
    //    /// Link의 StartCap 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    StartCap,

    //    /// <summary>
    //    /// Link의 Stretchable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Stretchable,

    //    /// <summary>
    //    /// Element의 Tag 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Tag,

    //    /// <summary>
    //    /// Element의 Text 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Text,

    //    /// <summary>
    //    /// Element의 TextColor가 변경된 상태입니다.
    //    /// </summary>
    //    TextColor,

    //    /// <summary>
    //    /// Node가 TextMargin 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    TextMargin,

    //    /// <summary>
    //    /// Element의 ToolTip 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Tooltip,

    //    /// <summary>
    //    /// Element의 Transparent 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Transparent,

    //    /// <summary>
    //    /// Node의 Trimming 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Trimming,

    //    /// <summary>
    //    /// Element의 Url 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    Url,

    //    /// <summary>
    //    /// Node의 XMoveable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    XMoveable,

    //    /// <summary>
    //    /// Node의 XSizeable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    XSizeable,

    //    /// <summary>
    //    /// Node의 YMoveable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    YMoveable,

    //    /// <summary>
    //    /// Node가 YSizeable 프로퍼티가 변경된 상태입니다.
    //    /// </summary>
    //    YSizeable,

    //    /// <summary>
    //    /// Element의 Zorder가 변경된 상태입니다.
    //    /// </summary>
    //    ZOrder
    //}

    

    ///// <summary>
    ///// Link의 Arrow의 각도 설명합니다.
    ///// </summary>
    //public enum ArrowAngle
    //{
    //    /// <summary>
    //    /// 15도를 나타냅니다.
    //    /// </summary>
    //    deg15,

    //    /// <summary>
    //    /// 30도를 나타냅니다.
    //    /// </summary>
    //    deg30,

    //    /// <summary>
    //    /// 45도를 나타냅니다.
    //    /// </summary>
    //    deg45
    //}

    ///// <summary>
    ///// Link의 Arrow의 Size 설명합니다.
    ///// </summary>
    //public enum ArrowSize
    //{
    //    /// <summary>
    //    /// VerySmall 크기 입니다.
    //    /// </summary>
    //    VerySmall,

    //    /// <summary>
    //    /// Small 크기 입니다.
    //    /// </summary>
    //    Small,

    //    /// <summary>
    //    /// Medium 크기 입니다.
    //    /// </summary>
    //    Medium,

    //    /// <summary>
    //    /// Large Size
    //    /// </summary>
    //    Large
    //}

    ///// <summary>
    ///// Node가 Parent Element에 어떻게 Attach되었는지 설명합니다.
    ///// </summary>
    //public enum AttachmentStyle
    //{
    //    /// <summary>
    //    /// Parent가 이동하더라도 Node는 이동하지 않음을 나타냅니다
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// Parent Element이 이동(Parent가 Node인경우)하거나 Strech(Parent가 Link인 경우)되면 연결된 Node들이 그에 따라감을 나타냅니다
    //    /// </summary>
    //    Element,

    //    /// <summary>
    //    /// Parent가 Link인 경우, Node는 Link의 Origin Node가 이동한 경우에만 이동. Parent가 Node인 경우 이동하지안음(Node과 같음)을 나타냅니다
    //    /// </summary>
    //    OriginNode,

    //    /// <summary>
    //    /// Parent가 Link인 경우, Node는 Link의 Destination Node가 이동한 경우에만 이동. Parent가 Node인 경우 이동하지 않음을 나타냅니다
    //    /// </summary>
    //    DestinationNode
    //}

    ///// <summary>
    ///// Node의 AutoSize Behaviour를 설명합니다.
    ///// </summary>
    //public enum AutoSize
    //{
    //    /// <summary>
    //    /// AutoSize 하지 않음을 나타냅니다. (Default)
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// Picture의 Size를 Node의 Size에 맞춰서 적용함을 나타냅니다
    //    /// </summary>
    //    ImageToNode,

    //    /// <summary>
    //    /// Node의 Size를 Picture의 Size에 맞춰서 적용함을 나타냅니다
    //    /// </summary>
    //    NodeToImage,

    //    /// <summary>
    //    /// Node의 Size를 Text 치수에 맞춰서 적용함을 나타냅니다
    //    /// </summary>
    //    NodeToText
    //}

    ///// <summary>
    ///// Used to specify whether the background will remain untouched or not for the text in a node
    ///// </summary>
    //public enum BackMode
    //{
    //    /// <summary>
    //    /// The background remains untouched
    //    /// </summary>
    //    Transparent,

    //    /// <summary>
    //    /// The background is filled with the background color before the text (default).
    //    /// </summary>
    //    Opaque
    //}

    ///// <summary>
    ///// Link가 Node에 Attach되었을때 AdjustOrg 혹은 AdjustDst 프로퍼티가 true인 상태를 설명합니다.
    ///// </summary>
    //public enum ConnectionStyle
    //{
    //    /// <summary>
    //    /// Link의 End point는 Node 내부, 경계선, 외부에 위치할 수 있음을 나타냅니다.
    //    /// </summary>
    //    EveryWhere,

    //    /// <summary>
    //    /// Link의 End point는 Node의 경계선이나 내부에 위치할 수 있음을 나타냅니다.
    //    /// </summary>
    //    Inside
    //}

    ///// <summary>
    ///// Cursor Setting
    ///// </summary>
    //public enum CursorSetting
    //{
    //    /// <summary>
    //    /// Cursor Setting이 없음을 나타냅니다.
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// Node Resize시 사용되는 Resize Cursor를 나타냅니다.
    //    /// </summary>
    //    Resize,

    //    /// <summary>
    //    /// Node Resize시에 Resize 커서를, Node Drag시에 Drag Cursor를 사용함을 나타냅니다.
    //    /// </summary>
    //    ResizeAndDrag,

    //    /// <summary>
    //    /// 모든 Cursor를 각각의action에 따라 사용함을 나타냅니다.
    //    /// </summary>
    //    All
    //}

    ///// <summary>
    ///// Cycle이 수용 되는지 안되는지에 대해 설명합니다.
    ///// </summary>
    //public enum CycleMode
    //{
    //    /// <summary>
    //    /// Cycle이 허용됨을 나타냅니다 (Default)
    //    /// </summary>
    //    CycleAllowed,

    //    /// <summary>
    //    /// Cycle 허용되지 않음을 나타냅니다.
    //    /// </summary>
    //    NoCycle,

    //    /// <summary>
    //    /// Directed Cycle이 허용되지 않음을 나타냅니다.
    //    /// </summary>
    //    NoDirectedCycle
    //}

    ///// <summary>
    ///// OwnerDraw 프로퍼티가 어떻게 사용되었는지를 설명합니다.
    ///// </summary>
    //public enum DrawFlags
    //{
    //    /// <summary>
    //    /// Diagram 전체가 Owner에 의해 Draw된 상태입니다.
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// Diagram 전체가 DiagramModeler에 의해 Draw된 상태입니다.
    //    /// </summary>
    //    All
    //}

    ///// <summary>
    ///// Error Event type을 설명합니다.
    ///// </summary>
    //public enum ErrorEventType
    //{
    //    /// <summary>
    //    /// Graph가 Acyclic하지 않음을 나타냅니다.
    //    /// </summary>
    //    CycleError,

    //    /// <summary>
    //    /// Graph가 Directed acyclic하지 않음을 나타냅니다.
    //    /// </summary>
    //    DirectedCycleError,

    //    /// <summary>
    //    /// 두 Node 사이에 다중 링크가 Accept되지 않음을 나타냅니다.
    //    /// </summary>
    //    MultilinkError,

    //    /// <summary>
    //    /// Reflective Link가 Accept되지 않음을 나타냅니다.
    //    /// </summary>
    //    ReflexiveError,

    //    /// <summary>
    //    /// Node는 Incoming Link를 Accept하지 않음을 나타냅니다.
    //    /// </summary>
    //    IncomingLinkError,

    //    /// <summary>
    //    /// Node가 Outging Link를 Accept하지 않음을 나타냅니다.
    //    /// </summary>
    //    OutgoingLinkError
    //}

    ///// <summary>
    ///// Node와 Link 선택 Handle의 Size를 설명합니다.
    ///// </summary>
    //public enum HandleSize
    //{
    //    /// <summary>
    //    /// 작은 Handle 크기 입니다.
    //    /// </summary>
    //    Small,

    //    /// <summary>
    //    /// 중간 Handle 크기 입니다.
    //    /// </summary>
    //    Medium,

    //    /// <summary>
    //    /// 큰 Handle 크기 입니다.
    //    /// </summary>
    //    Large
    //}

    ///// <summary>
    ///// Node상에서 Image의 위치를 설명합니다.
    ///// </summary>
    //public enum ImagePosition
    //{
    //    /// <summary>
    //    /// Picture가 Node의 왼쪽 상단에 위치함을 나타냅니다.
    //    /// </summary>
    //    LeftTop,

    //    /// <summary>
    //    /// Picture가 Node의 왼쪽 중단에 위치함을 나타냅니다.
    //    /// </summary>
    //    LeftMiddle,

    //    /// <summary>
    //    /// Picture가 Node의 왼쪽 하단에 위치함을 나타냅니다.
    //    /// </summary>
    //    LeftBottom,

    //    /// <summary>
    //    /// Picture가 Node의 오른쪽 상단에 위치함을 나타냅니다.
    //    /// </summary>
    //    RightTop,

    //    /// <summary>
    //    /// Picture가 Node의 오른쪽 중단에 위치함을 나타냅니다.
    //    /// </summary>
    //    RightMiddle,

    //    /// <summary>
    //    /// Picture가 Node의 오른쪽 하단에 위치함을 나타냅니다.
    //    /// </summary>
    //    RightBottom,
        
    //    /// <summary>
    //    /// Picture가 Node의 중앙 상단에 위치함을 나타냅니다.
    //    /// </summary>
    //    CenterTop,
        
    //    /// <summary>
    //    /// Picture가 Node의 정 중앙에 위치함을 나타냅니다.
    //    /// </summary>
    //    CenterMiddle,

    //    /// <summary>
    //    /// Picture가 Node의 중앙 하단에 위치함을 나타냅니다.
    //    /// </summary>
    //    CenterBottom,

    //    /// <summary>
    //    /// Picture가 Text에 비례하여 위치함을 나타냅니다.
    //    /// </summary>
    //    RelativeToText,

    //    /// <summary>
    //    /// Picture가 Node상에서 임의의 위치에 위치함을 나타냅니다.
    //    /// </summary>
    //    Custom
    //}

    ///// <summary>
    ///// 사용자의 Action을 설명합니다.
    ///// </summary>
    //public enum InteractiveAction
    //{
    //    /// <summary>
    //    /// 사용자 Action이 없음을 나타냅니다.
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// 사용자가 Mouse를 이용하여 Node를 생성을 나타냅니다.
    //    /// </summary>
    //    Node,

    //    /// <summary>
    //    /// 사용자가 Mouse를 이용하여 Link를 생성을 나타냅니다.
    //    /// </summary>
    //    Link,

    //    /// <summary>
    //    /// 사용자가 Mouse를 이용하여 임의의 Elementd르 Drag함을 나타냅니다.
    //    /// </summary>
    //    Drag,

    //    /// <summary>
    //    /// 사용자가 Mouse를 이용하여 Node를 Resize함을 나타냅니다.
    //    /// </summary>
    //    Size,

    //    /// <summary>
    //    /// 사용자가 Mouse를 이용하여 Link를 Stretch함을 나타냅니다.
    //    /// </summary>
    //    Stretch,

    //    /// <summary>
    //    /// 사용자가 mouse를 이용하여 Element들을 선택함을 나타냅니다.
    //    /// </summary>
    //    Select
    //}

    ///// <summary>
    ///// 한 Set의 Element을 설명함 (Node와 Link들)
    ///// </summary>
    //public enum ElementSet
    //{
    //    /// <summary>
    //    /// 모든 Element들을 의미합니다
    //    /// </summary>
    //    Elements,

    //    /// <summary>
    //    /// 모든 Node들을 의미합니다
    //    /// </summary>
    //    Nodes,

    //    /// <summary>
    //    /// 모든 Link들을 의미합니다
    //    /// </summary>
    //    Links,

    //    /// <summary>
    //    /// 모든 선택 가능한 Element들을 의미합니다
    //    /// </summary>
    //    SelectableElements,

    //    /// <summary>
    //    /// 모든 선택 가능한 Node들을 의미합니다
    //    /// </summary>
    //    SelectableNodes,

    //    /// <summary>
    //    /// 모든 선택 가능한 Link들을 의미합니다
    //    /// </summary>
    //    SelectableLinks
    //}

    ///// <summary>
    ///// Link선의 Jump 형태를 설명합니다.
    ///// </summary>
    //public enum Jump
    //{
    //    /// <summary>
    //    /// 표시되는 Jump 없음을 나타냅니다.
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// Link들의 교차점에 작은 Arc 형대로 Jump가 표시됨을 나타냅니다.
    //    /// </summary>
    //    Arc,

    //    /// <summary>
    //    /// Link덜의 교차점에 Break가 표시됨을 나타냅니다.
    //    /// </summary>
    //    Break
    //}

    ///// <summary>
    ///// Link의 교차점에 위치하는 Jump의 Size를 설명합니다.
    ///// </summary>
    //public enum JumpSize
    //{
    //    /// <summary>
    //    /// 작은 Jump 크기 입니다
    //    /// </summary>
    //    Small,

    //    /// <summary>
    //    /// 중간 Jump 크기 입니다.
    //    /// </summary>
    //    Medium,

    //    /// <summary>
    //    /// 큰 Jump 크기 입니다.
    //    /// </summary>
    //    Large
    //}

    ///// <summary>
    ///// 사용자가 Link를 생성하는데 사용할 수 있는 방법
    ///// </summary>
    //public enum LinkCreationMode
    //{
    //    /// <summary>
    //    /// 사용자가 Link 생성을 선택된 Node로 클릭하는 작업을 통해 수행함을 나타냅니다
    //    /// </summary>
    //    AllNodeArea,

    //    /// <summary>
    //    /// 사용자가 Link 생성을 선택된 Node의 중앙에 Handle로 Clink하는 작업을 통해 수행을 나타냅니다.
    //    /// </summary>
    //    MiddleHandle
    //}

    ///// <summary>
    ///// LinkOwnerDraw 프로퍼티가 어떻게 사용되었는지를 설명합니다.
    ///// </summary>
    //public enum LinkDrawFlags
    //{
    //    /// <summary>
    //    /// DiagramModeler가 모든 Link를 Draw함을 나타냅니다.
    //    /// </summary>
    //    All = 7,

    //    /// <summary>
    //    /// DiagramModeler가 Arrow를 Draw함을 나타냅니다.
    //    /// </summary>
    //    Arrows = 2,

    //    /// <summary>
    //    /// Link가 전체적으로 Owner에 의해 Draw된 상태입니다.
    //    /// </summary>
    //    None = 0,

    //    /// <summary>
    //    /// DiagramModeler가 Link Shape를 Draw함을 나타냅니다.
    //    /// </summary>
    //    Shape = 1,

    //    /// <summary>
    //    /// DiagramModeler가 Link Text를 Draw함을 나타냅니다.
    //    /// </summary>
    //    Text = 4
    //}

    ///// <summary>
    ///// 사용자가 Link를 선택하기위해 클릭해야 하는 영역을 설명합니다.
    ///// </summary>
    //public enum LinkSelectionAreaWidth
    //{
    //    /// <summary>
    //    /// 사용자는 Link와 근접한 매우 좁은 범위 내에서 클릭해야함을 나타냅니다
    //    /// </summary>
    //    VerySmall,

    //    /// <summary>
    //    ///  사용자는 Link와 근접한 좁은 범위 내에서 클릭해야함을 나타냅니다
    //    /// </summary>
    //    Small,

    //    /// <summary>
    //    /// 사용자는 Link와 근접한 중간정도의 범위 내에서 클릭해야함을 나타냅니다
    //    /// </summary>
    //    Medium,

    //    /// <summary>
    //    /// 사용자는 Link와 근접한 넓은 영역을 클릭해야함을 나타냅니다
    //    /// </summary>
    //    Large
    //}

    ///// <summary>
    ///// 마우스를 이용한 사각의 영역선택과 관련된 Action을 설명합니다.
    ///// </summary>
    //public enum MouseAction
    //{
    //    /// <summary>
    //    /// 별다른 Action 없이 사각형을 Draw함을 나타냅니다
    //    /// </summary>
    //    DrawRectangle,

    //    /// <summary>
    //    /// None
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// 사각의 영역 내부에 일부분이라도 포함된 Element들을 선택을 나타냅니다
    //    /// </summary>
    //    Selection,

    //    /// <summary>
    //    /// 사각의 영역 내부에 완전하게 포함된 Element들을 선택을 나타냅니다
    //    /// </summary>
    //    Selection2,

    //    /// <summary>
    //    /// 사각의 영역을 Zoom을 나타냅니다
    //    /// </summary>
    //    Zoom,

    //    /// <summary>
    //    /// 사각의 영역을 1:1의 영상비를 보장하는 Zoom을 나타냅니다
    //    /// </summary>
    //    ZoomIsotropic
    //}

    ///// <summary>
    ///// 마우스에 의해 지적된 영역의 Type을 설명합니다.
    ///// </summary>
    //public enum MouseArea
    //{
    //    /// <summary>
    //    /// 마우스가 특정 영역의 밖을 지적하고 있음, 따라서 아무것도 가리키고 있지 않음을 나타냅니다.
    //    /// </summary>
    //    OutSide,

    //    /// <summary>
    //    /// 마우스가 Node의 왼쪽 상단 코너의 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    LeftUpSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 상단 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    UpSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 오른쪽 상단 코너의 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    RightUpSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 왼편 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    LeftSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 오른편 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    RightSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 왼편 하단 코너의 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    LeftDownSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 하단 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    DownSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 오른쪽 하단 코너의 Handle을 지적함을 나타냅니다
    //    /// </summary>
    //    RightDownSquare,

    //    /// <summary>
    //    /// 마우스가 Link의 Stretching Handle 영역을 지적함을 나타냅니다
    //    /// </summary>
    //    StretchSquare,

    //    /// <summary>
    //    /// 마우스가 Node의 코너쪽 Linking 핸들 영역을 지적함을 나타냅니다
    //    /// </summary>
    //    LinkSquare,

    //    /// <summary>
    //    /// 마우스가 Drag를 위해 사용되는 Node frame을 지적함을 나타냅니다
    //    /// </summary>
    //    NodeDragFrame,

    //    /// <summary>
    //    /// 마우스가 Link 영역을 지적함을 나타냅니다
    //    /// </summary>
    //    Link,

    //    /// <summary>
    //    /// 마우스가 Node 영역을 선택함을 나타냅니다
    //    /// </summary>
    //    Node
    //}
    
    ///// <summary>
    ///// NodeOwnerDraw 프로퍼티가 어떻게 사용되었는가를 설명합니다.
    ///// </summary>
    //public enum NodeDrawFlags
    //{
    //    /// <summary>
    //    /// DiagramModeler가 모든 Node를 Draw함을 나타냅니다
    //    /// </summary>
    //    All = 0x1f,

    //    /// <summary>
    //    /// DiagramModeler가 Node를 Fill Color로 채움을 나타냅니다
    //    /// </summary>
    //    Fill = 2,

    //    /// <summary>
    //    /// DiagramModeler가 Node Image를 Draw함을 나타냅니다.
    //    /// </summary>
    //    Image = 8,

    //    /// <summary>
    //    /// Node가 전체적으로 Owner에 의해 Draw된 상태입니다.
    //    /// </summary>
    //    None = 0,

    //    /// <summary>
    //    /// DiagramModeler가 Node Shadow를 Draw함을 나타냅니다
    //    /// </summary>
    //    Shadow = 0x10,

    //    /// <summary>
    //    /// DiagramModeler가 Node Shape를 Draw함을 나타냅니다
    //    /// </summary>
    //    Shape = 1,

    //    /// <summary>
    //    /// DiagramModeler가 Node Text를 Draw함을 나타냅니다
    //    /// </summary>
    //    Text = 4
    //}

    ///// <summary>
    ///// 사용자가 Link 포인트를 Drag하여 특정 위치(Link Point들을 둘러싼 Link의 뭉툭한 모서리)로 이동시킴으로서 제거 할 수 있는지에 대해 설명합니다.
    ///// </summary>
    //public enum RemovePointAngle
    //{
    //    /// <summary>
    //    /// 두 선분이 엄격하게 정렬된경우에 Point가 삭제 됩니다.
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// Small Angle을 나타냅니다
    //    /// </summary>
    //    Small,

    //    /// <summary>
    //    /// Medium Angle을 나타냅니다
    //    /// </summary>
    //    Medium,

    //    /// <summary>
    //    /// Large Angel을 나타냅니다
    //    /// </summary>
    //    Large
    //}

    ///// <summary>
    ///// Link 선분의 코너를 둥글게 하는 정도의 Size를 설명합니다.
    ///// </summary>
    //public enum RoundedCornerSize
    //{
    //    /// <summary>
    //    /// 작은 크기를 나타냅니다
    //    /// </summary>
    //    Small,

    //    /// <summary>
    //    /// 중간 크기를 나타냅니다
    //    /// </summary>
    //    Medium,

    //    /// <summary>
    //    /// 큰 크기를 나타냅니다
    //    /// </summary>
    //    Large
    //}

    ///// <summary>
    ///// AutoScrollMinSize가 어떻게 Set될지에 대한 설명합니다.
    ///// </summary>
    //public enum ScrollbarsDisplayMode
    //{
    //    /// <summary>
    //    /// Diagram의 Size에 Control의 Size를 더하여 설정함을 나타냅니다.
    //    /// </summary>
    //    AddControlSize,

    //    /// <summary>
    //    /// Diagram의 Size로 설정함을 나타냅니다.
    //    /// </summary>
    //    SizeOfDiagramOnly
    //}

    ///// <summary>
    ///// Node의 Shadow Style을 설명합니다.
    ///// </summary>
    //public enum ShadowStyle
    //{
    //    /// <summary>
    //    /// Shadow 없음을 나타냅니다. (Default)
    //    /// </summary>
    //    None,

    //    /// <summary>
    //    /// 우측 하단 Shadow를 나타냅니다
    //    /// </summary>
    //    RightBottom,

    //    /// <summary>
    //    /// 우측 상단 Shadow를 나타냅니다
    //    /// </summary>
    //    RightTop,

    //    /// <summary>
    //    /// 좌측 상당 Shadow를 나타냅니다
    //    /// </summary>
    //    LeftTop,

    //    /// <summary>
    //    /// 좌측 하단 Shadow를 나타냅니다
    //    /// </summary>
    //    LeftBottom
    //}

    ///// <summary>
    ///// Node의 Shape 방향을 설명합니다.
    ///// </summary>
    //public enum ShapeOrientation
    //{
    //    /// <summary>
    //    /// 0 도를 나타냅니다
    //    /// </summary>
    //    so_0,

    //    /// <summary>
    //    /// 90 도를 나타냅니다
    //    /// </summary>
    //    so_90,

    //    /// <summary>
    //    /// 180 도를 나타냅니다
    //    /// </summary>
    //    so_180,

    //    /// <summary>
    //    /// 270 도를 나타냅니다
    //    /// </summary>
    //    so_270
    //}
  
    ///// <summary>
    ///// Zoom Type 설명합니다.
    ///// </summary>
    //public enum ZoomType
    //{
    //    /// <summary>
    //    /// 등방성 Zoom을 나타냅니다( 1:1 영상비 보장 )
    //    /// </summary>
    //    Isotropic,

    //    /// <summary>
    //    /// 이방성 Zoom을 나타냅니다
    //    /// </summary>
    //    Anisotropic
    //}

    #endregion

}
