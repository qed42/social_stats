<?php

/**
 * @file
 * Returns a content type with number of facebook  likes + comments + shares
 * comments on the node.
 * Only available on on node view i.e. with required context node being viewed
 */

$plugin = array(
  'title' => t('Facebook Total (likes + comments + shares)'),
  'content_types' => 'facebook_total',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_facebook_total_form_edit',
  'render callback' => 'social_stats_facebook_total_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

/**
 * Function to render the total count.
 */
function social_stats_facebook_total_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $total_count = db_select('social_stats_facebook', 'fb')
                  ->fields('fb')
                  ->condition('fb.nid', $args[0])
                  ->execute()
                  ->fetchObject();
  if ($total_count->fb_total == '1') {
    $block->content = 'total: ' . $total_count->fb_total;
  }
  else {
    $block->content = 'total: ' . $total_count->fb_total;
  }  
  return $block;
}

function social_stats_facebook_total_form_edit($form, &$form_state) {
  return $form;
}
