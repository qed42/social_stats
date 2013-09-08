<?php

/**
 * @file
 * Returns a content type with 
 * Facebook total + plus one count + tweets count + linkedin shares number 
 * of facebook shares of the node. Only available on on node view i.e. with
 * required context node being viewed
 */
$plugin = array(
  'title' => t('Total virality (Facebook total + plus one count + tweets count + linkedin shares'),
  'content_types' => 'total',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_total_form_edit',
  'render callback' => 'social_stats_total_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

/**
 * Function to render the share count.
 */
function social_stats_total_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $total_count = db_select('social_stats_total', 't')
                  ->fields('t')
                  ->condition('t.nid', $args[0])
                  ->execute()
                  ->fetchObject();
  if ($total_count->total_virality == '1') {
    $block->content = $total_count->total_virality . ' share';
  }
  else {
    $block->content = $total_count->total_virality . ' shares';
  }  
  return $block;
}

/**
 * Function to render the edit form, if not used doesn't get a form at all.
 */
function social_stats_total_form_edit($form, &$form_state) {
  return $form;
}
