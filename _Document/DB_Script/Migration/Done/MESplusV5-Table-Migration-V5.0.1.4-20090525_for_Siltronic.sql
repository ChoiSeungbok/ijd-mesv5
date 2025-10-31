/*
**
**  File Name    : MESplusV5-Table-Migration for Siltronic.sql
**  Description  : MESplus V5 Release Script for Siltronic regarding ID Generator Rule and Sequence Key table
**                     - Add optional sequence key member "FACTORY". It used to be a mandatory sequence key member.
**                     - This special migration script to change ID Generator Rule definition and ID Generator Sequence Key table for this change
**                     - Script is different by whether the sequence rule is based on Factory or not.
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Release Version : MESplus V5.0.1.4
**
*/

-- Factory wide ID Generator Rule
UPDATE MWIPIDGSKV set factory = ' '
where rule_id in ('PPN_CREATE', 'CPN_CREATE', 'SPN_CREATE', 'SUBLOT_CREATE', 'SilJobID');

-- Factory based ID Generator Rule
UPDATE MWIPIDGRUL set seq_key_1 = 'Y_________'
where rule_id = 'CARRIER'
and   rule_seq = 2;

-- Slicing Batch rule (SLICINGBATCH_ID)
-- This is date/time basis and no sequence
