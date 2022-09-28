// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/resize_store_hash_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s resize related functions, when the
 * hash value is stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::entry_pointer
PB_DS_CLASS_C_DEC::
resize_imp_no_exceptions_reassign_pointer(entry_pointer p_e, entry_pointer_array a_p_entries_resized, true_type)
{
  const comp_hash pos_hash_pair =
    ranged_hash_fn_base::operator()(PB_DS_V2F(p_e->m_value), p_e->m_hash);

  entry_pointer const p_next_e = p_e->m_p_next;
  p_e->m_p_next = a_p_entries_resized[pos_hash_pair.first];
  a_p_entries_resized[pos_hash_pair.first] = p_e;
  return p_next_e;
}
#endif
