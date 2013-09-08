<?php

/**
 * @file
 * Returns a content type with number of Google plus shares of the node.
 * Only available on on node view i.e. with required context node being viewed
 */

$plugin = array(
  'title' => t('Google Plus: plus one count'),
  'content_types' => 'google_plus',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_google_plus_form_edit',
  'render callback' => 'social_stats_google_plus_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

/**
 * Function to render the share count.
 */
function social_stats_google_plus_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $plusone_count = db_select('social_stats_gplus', 'g')
                  ->fields('g')
                  ->condition('g.nid', $args[0])
                  ->execute()
                  ->fetchObject();
  if ($plusone_count->plusone == '1') {
    $block->content = $plusone_count->plusone . ' share';
  }
  else {
    $block->content = $plusone_count->plusone . ' shares';
  }
  return $block;
}

/**
 * Function to render the edit form, if not used doesn't get a form at all.
 */
function social_stats_google_plus_form_edit($form, &$form_state) {
  return $form;
}
