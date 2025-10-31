using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
using System.IO;
using System.Windows.Forms;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{

    /// <summary>
    /// Diagram의 전체 설정값을 다루는 클래스 입니다.( Snap키 사용여부, 작업공간 넓이와 높이 )
    /// </summary>
    [Serializable]
    public class DiagramSettings
    {

        public class ShapeColorSet
        {
            public Color BackGradient;
            public Color FrontGradient;
            public Color ChildConnection;

            public ShapeColorSet(Color back, Color front, Color child)
            {
                BackGradient = back;
                FrontGradient = front;
                ChildConnection = child;
            }
        }

        /// <summary>
        /// DiagramSetting 클래스 입니다.
        /// </summary>
        [Serializable]
        public sealed class Settings
        {

            #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            int workspaceWidth = 3200;
            int workspaceHeight = 2400;

            float zoom = 1.0f;

            int currentCustomNodeIndex = 0;
            int currentCustomConnectionIndex = 0;
            int currentCustomHolderIndex = 0;

            bool useCustomNode = false;
            bool useCustomConnection = false;
            bool useCustomConnectionHolder = false;

            bool usePrecisionSnapping = true;
            bool useGrid = true;
            bool useGridSnapping = false;
            bool useVirtualMoving = false;

            ConnectionProperty connectionProperty;
            ConnectionProperty previewConnectionProperty;

            /// <summary>
            /// 다이어 그램의 배경색
            /// </summary>
            Color diagramBackColor = Color.White;

            List<ShapeColorSet> lisShapeColorSet = new List<ShapeColorSet>();

            #endregion


            #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            /// <summary>
            /// Diagram의 바탕색 프로퍼티 입니다.
            /// </summary>
            public Color DiagramBackColor
            {
                get { return diagramBackColor; }
                set { diagramBackColor = value; }
            }

            /// <summary>
            /// 입력되어 있는 CustomNode중 현재 사용하려는 노드의 번호를 변경하거나 가져오는 프로퍼티 입니다.
            /// </summary>
            public int CurrentCustomNodeIndex
            {
                get { return currentCustomNodeIndex; }
                set { currentCustomNodeIndex = value; }
            }

            /// <summary>
            /// 입력되어 있는 CustomConnection중 현재 사용하려는 간선의 번호를 변경하거나 가져오는 프로퍼티 입니다.
            /// </summary>
            public int CurrentCustomConnectionIndex
            {
                get { return currentCustomConnectionIndex; }
                set { currentCustomConnectionIndex = value; }
            }

            /// <summary>
            /// 입력되어 있는 CustomConnectionHolder중 현재 사용하려는 ConnectionHoldeer를 변경하거나 가져오는 프로퍼티 입니다.
            /// </summary>
            public int CurrentCustomHolderIndex
            {
                get { return currentCustomHolderIndex; }
                set { currentCustomHolderIndex = value; }
            }

            /// <summary>
            /// 기본적으로 적용할 Line object를 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public ConnectionProperty ConnectionProperty
            {
                get { return connectionProperty; }
                set { connectionProperty = value; }
            }


            /// <summary>
            /// 선 연결 미리보기에 사용되는 선을 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public ConnectionProperty PreviewConnectionProperty
            {
                get { return previewConnectionProperty; }
                set { previewConnectionProperty = value; }
            }

            /// <summary>
            /// 노드(도형) 생성에 사용자 정의(상속을 통한 정의) 노드를 사용하도록 할 것인지를 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public bool UseCustomNode
            {
                get { return useCustomNode; }
                set { useCustomNode = value; }
            }

            /// <summary>
            /// 간선 생성에 사용자 정의(상속을 통한 정의) 간선을 사용하도록 할 것인지를 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public bool UseCustomConnection
            {
                get { return useCustomConnection; }
                set { useCustomConnection = value; }
            }

            /// <summary>
            /// DefaultHolder 생성에 사용자 정의(상속을 토한 정의) ConnectionHolder를 사용하도록 할 것인지를 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public bool UseCustomConnectionHolder
            {
                get { return useCustomConnectionHolder; }
                set { useCustomConnectionHolder = value; }
            }


            /// <summary>
            /// 잡아끌기 작업의 수행여부에 대한 프로퍼티 입니다.
            /// </summary>
            public bool UsePrecisionSnapping
            {
                get { return usePrecisionSnapping; }
                set { usePrecisionSnapping = value; }
            }

            /// <summary>
            /// 디자인 영역에서 DiagramGrid 사용여부에 대한 값을 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public bool UseDiagramGrid
            {
                get { return useGrid; }
                set { useGrid = value; }
            }

            /// <summary>
            /// Grid에 대해 잡아 끌기 기능 사용여부에 대한 값을 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public bool UseGridSnapping
            {
                get { return useGridSnapping; }
                set { useGridSnapping = value; }
            }

            /// <summary>
            /// 도형 이동시 가상으로 이동시킬지 여부에 대한 값을 가져오거나 설정하는 프로퍼티 입니다.(마우스 Up시 실제로 이동)
            /// </summary>
            public bool UseVirtualMoving
            {
                get { return useVirtualMoving; }
                set { useVirtualMoving = value; }
            }

            /// <summary>
            /// 그리기 Zoom 배율을 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public float Zoom
            {
                get { return zoom; }
                set { zoom = value; }
            }

            /// <summary>
            /// 작업공간 넓이값에 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public int WorkspaceWidth
            {
                get
                {
                    return workspaceWidth;
                }
                set
                {
                    if (value >= 100 && value <= 10000)
                        workspaceWidth = value;
                }
            }

            /// <summary>
            /// 작업공간 높이값에 가져오거나 설정하는 프로퍼티 입니다.
            /// </summary>
            public int WorkspaceHeight
            {
                get
                {
                    return workspaceHeight;
                }
                set
                {
                    if (value >= 100 && value <= 10000)
                        workspaceHeight = value;
                }
            }

            /// <summary>
            /// 
            /// </summary>
            public List<ShapeColorSet> ShapeColorSets
            {
                get
                {
                    return lisShapeColorSet;
                }
            }

            #endregion


            #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            /// <summary>
            /// 기본 생성자 입니다.
            /// </summary>
            internal Settings()
            {
                connectionProperty = new ConnectionProperty(ArrowStyle.None, ArrowStyle.Nesting);
                previewConnectionProperty = new ConnectionProperty(ArrowStyle.Realization, ArrowStyle.Realization);

                lisShapeColorSet.Add(new ShapeColorSet(Color.FromArgb(255, 234, 184, 245)  , Color.FromArgb(255, 158, 118, 200), Color.FromArgb(255, 124, 205, 50)));
                lisShapeColorSet.Add(new ShapeColorSet(Color.FromArgb(255, 229, 230, 188)  , Color.FromArgb(255, 173, 174, 99) , Color.FromArgb(255, 255, 69, 00)));
                lisShapeColorSet.Add(new ShapeColorSet(Color.FromArgb(255, 253, 223, 67)   , Color.FromArgb(255, 238, 143, 18) , Color.FromArgb(255, 169, 169, 169)));
                lisShapeColorSet.Add(new ShapeColorSet(Color.GhostWhite                    , Color.FromArgb(255, 171, 171, 171), Color.FromArgb(255, 171, 171, 171)));
                lisShapeColorSet.Add(new ShapeColorSet(Color.FromArgb(255, 187, 224, 227)  , Color.FromArgb(255, 60, 173, 196) , Color.FromArgb(255, 84, 141, 160)));
                lisShapeColorSet.Add(new ShapeColorSet(Color.FromArgb(255, 192, 222, 208)  , Color.FromArgb(255, 46, 184, 141) , Color.FromArgb(255, 35, 141, 108)));
                lisShapeColorSet.Add(new ShapeColorSet(Color.FromArgb(255, 247, 205, 233)  , Color.FromArgb(255, 230, 96, 163) , Color.FromArgb(255, 213, 33, 123)));
                lisShapeColorSet.Add(new ShapeColorSet(Color.FromArgb(255, 228, 236, 178)  , Color.FromArgb(255, 161, 153, 95) , Color.FromArgb(255, 113, 108, 67)));

            }

            #endregion

            #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            public ShapeColorSet GetShapeColorSet(int level)
            {
                if (this.lisShapeColorSet.Count < level / 10)
                    return this.lisShapeColorSet[0];

                return this.lisShapeColorSet[level / 10];
            }

            #endregion
        }

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        Settings diagramSettings = new Settings();

        /// <summary>
        /// DiagramSettins Object
        /// </summary>
        static Settings currentSettings = new Settings();

        /// <summary>
        /// 파일 경로를 나타내는 string 값입니다.
        /// </summary>
        protected static readonly string FilePath = Path.Combine(Application.StartupPath, "DiagramSettings.xml");

        #endregion
    

        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        #region Static properties >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        //public static List<ShapeColorSet> ShapeColorSets
        //{
        //    get { return currentSettings.ShapeColorSets; }
        //}

        /// <summary>
        /// 리스트에서 현재 사용되고 있는 사용자 정의 노드(도형)의 인덱스를 설정하거나 가져옵니다.
        /// </summary>
        public static int CurrentCustomNodeIndex
        {
            get { return currentSettings.CurrentCustomNodeIndex;  }
            set { currentSettings.CurrentCustomNodeIndex = value; }
        }

        /// <summary>
        /// 리스트에서 현재 사용되고 있는 사용자 정의 Connection의 인덱스를 설정하거나 가져옵니다.
        /// </summary>
        public static int CurrentCustomConnectionIndex
        {
            get { return currentSettings.CurrentCustomConnectionIndex;  }
            set { currentSettings.CurrentCustomConnectionIndex = value; }
        }

        /// <summary>
        /// 리스트에서 현재 사용되고 있는 사용자 정의 ConnectionHolder의 인덱스를 설정하거나 가져옵니다.
        /// </summary>
        public static int CurrentCustomConnectionHolderIndex
        {
            get { return currentSettings.CurrentCustomHolderIndex;  }
            set { currentSettings.CurrentCustomHolderIndex = value; }
        }

        /// <summary>
        /// 기본적으로 적용할 Line object를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static ConnectionProperty ConnectionProperty
        {
            get { return currentSettings.ConnectionProperty; }
            set { currentSettings.ConnectionProperty = value; }
        }

        /// <summary>
        /// 선 연결 미리보기에 사용되는 선을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static ConnectionProperty PreviewConnectionProperty
        {
            get { return currentSettings.PreviewConnectionProperty; }
            set { currentSettings.PreviewConnectionProperty = value; }
        }

        /// <summary>
        /// 사용자 정의 노드(도형)을 사용할지에 대해 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static bool UseCustomNode
        {
            get { return currentSettings.UseCustomNode;  }
            set { currentSettings.UseCustomNode = value; }
        }

        /// <summary>
        /// 사용자 정의 Connection을 사용할지에 대해 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static bool UseCustomConnection
        {
            get { return currentSettings.UseCustomConnection;  }
            set { currentSettings.UseCustomConnection = value; }
        }

        /// <summary>
        /// 사용자 정의 ConnectionHolder를 사용할지에 대해 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static bool UseCustomConnectionHolder
        {
            get { return currentSettings.UseCustomConnectionHolder;  }
            set { currentSettings.UseCustomConnectionHolder = value; }
        }

        /// <summary>
        /// 잡아끌기 작업의 수행여부에 대한 프로퍼티 입니다.
        /// </summary>        
        public static bool UsePrecisionSnapping
        {
            get { return currentSettings.UsePrecisionSnapping;  }
            set { currentSettings.UsePrecisionSnapping = value; }
        }

        /// <summary>
        /// 디자인 영역에서 DiagramGrid 사용여부에 대한 값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static bool UseDiagramGrid
        {
            get { return currentSettings.UseDiagramGrid;  }
            set { currentSettings.UseDiagramGrid = value; }
        }

        /// <summary>
        /// Grid에 대해 잡아 끌기 기능 사용여부에 대한 값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static bool UseDiagramGridSnapping
        {
            get { return currentSettings.UseGridSnapping;  }
            set { currentSettings.UseGridSnapping = value; }
        }

        /// <summary>
        /// 도형이동시 가상으로 이동시킬지 여부에 대한 값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static bool UseVirtualMoving
        {
            get { return currentSettings.UseVirtualMoving;  }
            set { currentSettings.UseVirtualMoving = value; }
        }

        /// <summary>
        /// 그리기 Zoom 배율을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static float Zoom
        {
            get { return currentSettings.Zoom;  }
            set { currentSettings.Zoom = value; }
        }

        /// <summary>
        /// 작업공간 넓이값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static int WorkspaceWidth
        {
            get { return currentSettings.WorkspaceWidth; }
            set { currentSettings.WorkspaceWidth = value; }
        }

        /// <summary>
        /// 작업공간 높이값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public static int WorkspaceHeight
        {
            get { return currentSettings.WorkspaceHeight; }
            set { currentSettings.WorkspaceHeight = value; }
        }

        /// <summary>
        /// Diagrma 배경색을 가져오거나 설정하는 포로퍼티 입니다.
        /// </summary>
        public static Color DiagramBackColor
        {
            get { return currentSettings.DiagramBackColor; }
            set { currentSettings.DiagramBackColor = value; }
        }

        #endregion

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        public static ShapeColorSet GetShapeColorSet(int level)
        {
            return currentSettings.GetShapeColorSet(level);
        }

        public static bool GetSortDirection(int level)
        {
            return ((level / 10) % 2 == 0);
        }


        /// <summary>
        /// 설정값을 불러옵니다.
        /// </summary>
        /// <returns></returns>
        public static bool LoadSettings()
        {
            return true;
            //return LoadSettings(FilePath);            
        }

        /// <summary>
        /// 설정값을 불러옵니다.
        /// </summary>
        /// <param name="filePath">파일경로</param>
        /// <returns>결과 True/False</returns>
        public static bool LoadSettings(string filePath)
        {
            try
            {
                using (XmlTextReader reader = new XmlTextReader(filePath))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(Settings));
                    Settings settings = (Settings)serializer.Deserialize(reader);

                    currentSettings = settings;
                    return true;
                }
            }
            catch(Exception e)
            {
                MessageBox.Show(e.Message, "DiagramSettings");
                return false;
            }
        }

        /// <summary>
        /// 설정값을 저장합니다.
        /// </summary>
        /// <returns>결과 True/False</returns>
        public static bool SaveSettings()
        {
            return true;
            //return SaveSettings(FilePath);
        }

        /// <summary>
        ///  설정값을 저장합니다.
        /// </summary>
        /// <param name="filePath">파일경로</param>
        /// <returns>결과 True/False</returns>
        public static bool SaveSettings(string filePath)
        {
            try
            {
                using (TextWriter writer = new StreamWriter(filePath))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(Settings));
                    XmlSerializerNamespaces namespaces = new XmlSerializerNamespaces();
                    namespaces.Add("", "");

                    serializer.Serialize(writer, currentSettings, namespaces);
                    return true;
                }
            }
            catch
            {
                return false;
            }
        }

        #endregion

    }
}
