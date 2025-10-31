using System;
using System.Collections.Generic;
using System.Text;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 관계 규칙 클래스 입니다.
    /// </summary>
    public sealed class ConnectionRule
    {
        private string _value;
        private bool _isAllowed;

        /// <summary>
        /// 관계 규칙을 생성합니다.
        /// </summary>
        /// <param name="pair"></param>
        public ConnectionRule(string pair)
        {
            Value = pair;
            IsAllowed = true;
        }

        /// <summary>
        /// 관계 규칙을 생성합니다.
        /// </summary>
        /// <param name="pair"></param>
        /// <param name="isAllowed"></param>
        public ConnectionRule(string pair, bool isAllowed)
        {
            Value = pair;
            IsAllowed = isAllowed;
        }

        /// <summary>
        /// 관계 규칙값을 가져오거나 설정하는 프로퍼티입니다.
        /// </summary>
        public string Value
        {
            get
            {
                return this._value;
            }
            set
            {
                this._value = value;
            }
        }

        /// <summary>
        /// 해당 관계 규칙값을 허용하는지 여부를 가져오거나 설정하는 프로퍼티입니다.
        /// </summary>
        public bool IsAllowed
        {
            get
            {
                return this._isAllowed;
            }
            set
            {
                this._isAllowed = value;
            }
        }
    }

    /// <summary>
    /// 관계 규칙 집합 클래스 입니다.
    /// </summary>
    public class ConnectionRuleSet
    {
        private List<ConnectionRule> _rules4mixed = null;
        private List<string> _rules = null;
        private ConnectionRuleType _ruleType;

        /// <summary>
        /// ConnectionRule 집합을 Default 종류로 생성합니다.
        /// </summary>
        public ConnectionRuleSet()
        {
            this._ruleType = ConnectionRuleType.Default;
        }

        /// <summary>
        /// ConnectionRule 집합을 생성합니다.
        /// </summary>
        /// <param name="ruleType">ConnectionRule 집합의 종류</param>
        public ConnectionRuleSet(ConnectionRuleType ruleType)
        {
            this._ruleType = ruleType;

            if (ruleType == ConnectionRuleType.Mix)
                _rules4mixed = new List<ConnectionRule>();
            else
                _rules = new List<string>();
        }

        /// <summary>
        /// 이 ConnectionRule 집합의 종류를 가져오는 프로퍼티 입니다.
        /// </summary>
        public ConnectionRuleType RuleType
        {
            get
            {
                return this._ruleType;
            }
        }

        /// <summary>
        /// 관계 규칙을 추가합니다.
        /// </summary>
        /// <param name="value">추가할 규칙값</param>
        /// <returns>관계가 추가되었는지에 대한 True/False</returns>
        public bool AddRule(string value)
        {
            // Default 타입은 모든 관계를 허용하기 때문에 관계 규칙 추가를 할수 없다.
            if (_ruleType == ConnectionRuleType.Default)
                return false;

            // 혼합모드는 관계를 허용하는지 않하는지에 대한 값을 함께 파라메터로 취하는 AddRule을 이용해야 한다.
            if(_ruleType == ConnectionRuleType.Mix)
                return false;

            // 기존에 동일한 관계가 있는경우 추가하지 않는다 (중복 방지)
            if (_rules.Contains(value))
                return false;
            else
                _rules.Add(value);                

            return true;
        }

        /// <summary>
        /// 관계 규칙을 추가합니다.
        /// </summary>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        public bool AddRule(Enum start, Enum end)
        {
            return AddRule(GetRuleValue(start, end));            
        }

        /// <summary>
        /// 관계 규칙을 추가합니다.
        /// </summary>
        /// <param name="value"></param>
        /// <param name="isAllowed"></param>
        /// <returns></returns>
        public bool AddRule(string value, bool isAllowed)
        {
            if (_ruleType == ConnectionRuleType.Default)
                return false;

            ConnectionRule rule = new ConnectionRule(value, isAllowed);
            ConnectionRule reverseRule = new ConnectionRule(value, !isAllowed);

            if (_ruleType != ConnectionRuleType.Mix)
                return false;

            if (!_rules4mixed.Contains(rule) && !_rules4mixed.Contains(reverseRule))
                _rules4mixed.Add(rule);
            else
                return false;

            return true;
        }

        /// <summary>
        /// 관계 규칙을 추가합니다.
        /// </summary>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <param name="isAllowed"></param>
        /// <returns></returns>
        public bool AddRule(Enum start, Enum end, bool isAllowed)
        {
            return AddRule(GetRuleValue(start,end),isAllowed);
        }

        /// <summary>
        /// 저장된 규칙에서 요청된 규칙을 허용하는지 여부를 확인합니다.
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public bool CheckRule(string value)
        {
            if (_ruleType == ConnectionRuleType.Default)
                return true;

            if (_ruleType == ConnectionRuleType.Mix)
            {
                foreach (ConnectionRule rule in _rules4mixed)
                {
                    if (rule.Value == value)
                        return rule.IsAllowed;
                }
            }
            else
            {
                if (_rules.Contains(value))
                    return (_ruleType == ConnectionRuleType.Allow);                    
            }

            return false;
        }

        /// <summary>
        /// 저장된 규칙에서 요청된 규칙을 허용하는지 여부를 확인합니다.
        /// </summary>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        public bool CheckRule(Enum start, Enum end)
        {
            return CheckRule(GetRuleValue(start, end));
        }

        /// <summary>
        /// 관계 규칙용 값을 생성합니다.
        /// </summary>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        private string GetRuleValue(Enum start, Enum end)
        {
            return start.ToString() + end.ToString();
        }
    }
}
