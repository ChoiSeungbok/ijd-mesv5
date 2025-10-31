package com.pda.mes.utils;

/**
 * Created by sjs on 2020. 09. 24
 */

public class StringUtil {

    public static boolean isNullOrEmpty(String value) {
        if(value == null) return true;
        if(value.trim().equals("")) return true;

        return false;
     }

    public static boolean isBlank(final CharSequence cs) {
        int strLen;
        if (cs == null || (strLen = cs.length()) == 0) {
            return true;
        }
        for (int i = 0; i < strLen; i++) {
            if (Character.isWhitespace(cs.charAt(i)) == false) {
                return false;
            }
        }
        return true;
    }
}
