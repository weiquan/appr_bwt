/*
 * =====================================================================================
 *
 *       Filename:  index.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年10月09日 17时23分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei Quan (wq), wquanhit@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __INDEX_H
#define __INDEX_H


#include <stdint.h>
#include "utils.h"
#include "variants.h"
#include "bwt.h"
#include "bntseq.h"
#include "bitmap.h"
#include "lookup.h"

typedef struct{
    uint32_t seq, idx;
} ext_t;
typedef struct{

    lkt_t *fastmap;/*fastmap 12bp seq*/
    bwt_t *bwt;/*FM index*/
    bntseq_t *bns;
    uint8_t *pac;/* packed reference seq */
    /* snp-aware seed index */
    int n_pmap;
    uint32_t *pmap;/* preseq map */ 
    int n_var;
    uint8_t *refseq;/*2bp refseq at variant site*/
    uint32_t *sai;/* sa index */
    
    /* approximate match */
    bp_t *is_multiseeds;/*is_multiseeds[i] = 1 if Reference[sa[i]:sa[i]+20] is multi location seeds */
    uint32_t n_isa2seq16;
    uint32_t* isa2seq16; /* isa2seq16[i] = start of seq16s, i is occ of 1 in is_multiseeds before isa*/
    uint32_t n_seq16s;
    uint32_t *seq16s;

    int n_tot;
    uint32_t *lext_idx;
    uint32_t *lext1_idx;
    uint32_t *rext_idx; 
    
    int n_rext, n_lext0, n_lext1;
    ext_t *rext0, *lext0;
    uint32_t *lext1;
    /* 
    bp_t *is_var;// variants map
    uint32_t n_var;
    uint32_t *var_seqs;// var_seqs[2i] = variant pre seq; var_seqs[2i+1] = variant index 
    all_var_t *var;*/
} idx_t;
idx_t *idx_restore(const char *prefix);
void idx_destroy(idx_t *idx);

#endif
