using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 엘러먼트 주위나 내부에 Text를 출력하는데 상요되는 클래스 입니다.
    /// </summary>
    public class ShapeLabel : ICloneable
    {

        /// <summary>
        /// Label에 들어갈 문자열을 다루는 클래스 입니다.
        /// </summary>
        public sealed class Text : ICloneable
        {

            #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            /// <summary>
            /// 표현할 문자열
            /// </summary>
            string value = "";

            /// <summary>
            /// 문자열의 색상
            /// </summary>
            Color color = Color.Black;

            #endregion


            #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            /// <summary>
            /// 문자열을 설정하거나 가져온느 프로퍼티 입니다.
            /// </summary>
            public string Value
            {
                get { return this.value;  }
                set { this.value = value; }
            }
            
            /// <summary>
            /// 생상을 설정하건나 가져오는 프로퍼티 입니다.
            /// </summary>
            public Color Color
            {
                get { return color;  }
                set { color = value; }
            }

            #endregion


            #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            /// <summary>
            /// 변환 생성자 입니다.
            /// </summary>
            /// <param name="str"></param>
            public Text(string str)
            {
                this.value = str;
            }

            /// <summary>
            /// 변환 생성자 입니다.
            /// </summary>
            /// <param name="str"></param>
            /// <param name="color"></param>
            public Text(string str, Color color)
            {
                this.value = str;
                this.color = color;
            }

            #endregion


            #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            /// <summary>
            /// 같은 Object를 복사합니다.
            /// </summary>
            /// <returns>복사하여 만들어진 Object</returns>
            public object Clone()
            {
                return new Text((string)this.value.Clone(), this.color);
            }

            #endregion

        }


        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 노드(도형) 배부에 표시될 Label인지에 대한 값
        /// </summary>
        bool innerText = false;

        /// <summary>
        /// string을 담고 있는 Text Object의 List
        /// </summary>
        List<Text> texts = new List<Text>();

        /// <summary>
        /// 수평 정렬 방식
        /// </summary>
        VerticalAlingment vertical = VerticalAlingment.Top;

        /// <summary>
        /// 수직 정렬 방식
        /// </summary>
        HorizontalAlignment horizontal = HorizontalAlignment.Center;

        /// <summary>
        /// Label을 소유한 노드(도형)
        /// </summary>
        BaseShape owner;

        /// <summary>
        /// 폰트
        /// </summary>
        Font font = new Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));

        #endregion

       
        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 노드(도형) 내부에 Draw할지에 대해 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public bool InnerText
        {
            get { return innerText;  }
            set { innerText = value; }
        }

        /// <summary>
        /// 폰트를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public Font Font
        {
            get { return font;  }
            set { font = value; }
        }

        /// <summary>
        /// 수직 정렬 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public VerticalAlingment VerticalAlignment
        {
            get { return vertical;  }
            set { vertical = value; }
        }

        /// <summary>
        /// 수평 정렬을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public HorizontalAlignment HorizontalAlignment
        {
            get { return horizontal;  }
            set { horizontal = value; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
        /// <summary>
        /// Label을 생성합니다.
        /// </summary>
        /// <param name="baseShape">문자열을 소유할 노드(도형)</param>
        /// <param name="innerText">노드 내부에 출력할 용도인지에 대한 True/False</param>
        public ShapeLabel(BaseShape baseShape, bool innerText)
        {
            if (baseShape == null)
                throw new Exception("BaseShape is Needed.");

            this.InnerText = innerText;

            this.owner = baseShape;
        }

        /// <summary>
        /// ElementLabel을 생성합니다
        /// </summary>
        /// <param name="str">문자열</param>
        /// <param name="baseShape">문자열을 소유할 노드(도형)</param>
        /// <param name="innerText">노드 내부에 출력할 용도인지에 대한 True/False</param>
        public ShapeLabel(string str, BaseShape baseShape, bool innerText)
        {            
            if(baseShape == null)
                throw new Exception("BaseShape is Needed.");

            this.InnerText = innerText;

            AddText(new Text(str));

            this.owner = baseShape;
        }

        /// <summary>
        /// ElementLabel을 생성합니다.
        /// </summary>
        /// <param name="text">Text 리스트</param>
        /// <param name="va">가로 정렬값</param>
        /// <param name="ha">세로 정렬값</param>
        private ShapeLabel(List<Text> text, VerticalAlingment va, HorizontalAlignment ha)
        {
            this.texts = text;
            this.vertical = va;
            this.horizontal = ha; 
        }

        #endregion

        
        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 문자열을 추가합니다.
        /// </summary>
        /// <param name="str">추가할 문자열</param>
        /// <returns>추가 되었는지에 대한 결과 True/False</returns>
        public bool AddString(string str)
        {
            if (str == null)
                return false;

            return AddText(new Text(str));
        }

        /// <summary>
        /// Text를 추가합니다.
        /// </summary>
        /// <param name="text">추가할 Text Object</param>
        /// <returns>추가 되었는지에 대한 결과 True/False</returns>
        public bool AddText(Text text)
        {
            if (text == null)
                return false;

            this.texts.Add(text);

            int iLength = (int)CalculateLabelLength();

            if (innerText)
            {
                if (iLength > 50)
                    owner.MinimumSize = new Size(iLength, owner.MinimumSize.Height);
                else
                    owner.MinimumSize = new Size(50, owner.MinimumSize.Height);

                owner.MaximumSize = owner.MinimumSize;
            }
            else
            {
                owner.MaximumSize = owner.MinimumSize;
            }

            return true;
        }

        /// <summary>
        /// Text를 리스트에서 제거합니다.
        /// </summary>
        /// <param name="text">제거할 Text Object</param>
        /// <returns>제거 되었는지에 대한 결과 True/False</returns>
        public bool DeleteText(Text text)
        {
            if (text == null)
                return false;

            if (this.texts.Contains(text))
                this.texts.Remove(text);
            else
                return false;

            return true;
        }

        /// <summary>
        /// 동일한 Object를 복사하여 만듭니다.
        /// </summary>
        /// <returns>복사하여 만들어진 Object</returns>
        public object Clone()
        {
            return new ShapeLabel(this.texts, this.vertical, this.horizontal);
        }

        /// <summary>
        /// Label을 Draw합니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="point">그릴 좌표</param>
        public void Draw(Graphics g, PointF point)
        {
            if (innerText)
                InDraw(g, point);
            else
                OutDraw(g, point);
        }

        /// <summary>
        /// 노드(도형) 내부에 Label을 Draw합니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="point">그릴 좌표</param>
        private void InDraw(Graphics g, PointF point)
        {
            //입력된 문자열이 없으면 Draw 하지 않음
            if (texts.Count == 0)
                return;

            foreach(Text text in texts)            
                g.DrawString(text.Value, font, new SolidBrush(text.Color), point);     
        }

        /// <summary>
        /// 노드(도형) 외부에 Label을 Draw합니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="point">그릴 좌표</param>
        private void OutDraw(Graphics g, PointF point)
        {
            //입력된 문자열이 없으면 Draw 하지 않음
            if (texts.Count == 0)
                return;

            PointF position = new PointF(owner.Left,owner.Top);

            // 정렬 설정에 따라 좌표값을 조정한다. ( 수직정렬 )
            switch (vertical)
            {
                case VerticalAlingment.Top:
                    position.Y -= 12;
                    break;
                case VerticalAlingment.Middle:
                    position.Y += (owner.Bottom - owner.Top - 10f) / 2.0f;
                    break;
                case VerticalAlingment.Bottom:
                    position.Y = owner.Bottom;
                    break;
            }

            // 정렬 설정에 따라 좌표값을 조정한다. ( 수평정렬 )
            switch (horizontal)
            {
                case HorizontalAlignment.Left:
                    position.X = owner.Left;
                    break;
                case HorizontalAlignment.Center:
                    position.X += (owner.Right - owner.Left) / 2.0f;
                    break;
                case HorizontalAlignment.Right:
                    position.X = owner.Right;
                    break;
            }

            for (int i = 0; i < texts.Count; i++)
            {
                g.DrawString(texts[i].Value, font, new SolidBrush(texts[i].Color), position);

                //한글, 대소문자, 공백을 구분하여 그에 따라 문자열의 길이를 계산하여 다음 문자열 출력의 좌표를 구합니다.
                foreach(char ch in texts[i].Value)
                {
                    //영문 이외의 문자
                    if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.OtherLetter)
                        position.X += 14;
                    //대문자
                    else if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.UppercaseLetter)
                        position.X += 8.9f;
                    //소문자
                    else if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.LowercaseLetter)
                        position.X += 7.1f;
                    //공백
                    else if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.SpaceSeparator)
                        position.X += 4.9f;
                    //그밖의 기호
                    else
                        position.X += 7.3f;
                }
            }
        }

        /// <summary>
        /// 문자에 대해 Font크기 기준으로 Draw간격을 계산합니다. (글꼴에 따른 변경 필요)
        /// </summary>
        /// <returns></returns>
        private float CalculateLabelLength()
        {
            float positionX = 12.0f;

            for (int i = 0; i < texts.Count; i++)
            {
                //한글, 대소문자, 공백을 구분하여 그에 따라 문자열의 길이를 계산하여 다음 문자열 출력의 좌표를 구합니다.
                foreach (char ch in texts[i].Value)
                {
                    //영문 이외의 문자
                    if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.OtherLetter)
                        positionX += 14 * ( Font.SizeInPoints / 10f );
                    //대문자
                    else if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.UppercaseLetter)
                        positionX += 12f * (Font.SizeInPoints / 10f);
                    //소문자
                    else if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.LowercaseLetter)
                        positionX += 7.1f * (Font.SizeInPoints / 10f);
                    //공백
                    else if (char.GetUnicodeCategory(ch) == System.Globalization.UnicodeCategory.SpaceSeparator)
                        positionX += 4.9f * (Font.SizeInPoints / 10f);                
                    //그밖의 기호
                    else
                        positionX += 8.9f * (Font.SizeInPoints / 10f);
                }
            }
            return positionX;
        }

        #endregion

    }
}
